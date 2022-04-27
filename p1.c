#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define high 300
#define mid 200
#define low 100
#define optimal 300
#define medium 200
#define small 100



int power(){
   int v,i,cos=1;
   printf("\nEnter the voltage data device\n");
   scanf("%d",&v);
   printf("\nEnter the current data\n");
   scanf("%d",&i);
   return(v*i*cos);
}

int read_dbms(char a[20], FILE *fp1) {
  char b[20], c[20];
  int x = 0;
  rewind(fp1);
  while (fscanf(fp1, "%s%s", b, c) != EOF)
    if (!strcmp(a, b))
      x = 1;
  return x;
}

void register_device(char a[20], int b) {
  FILE *fp1, *fp2, *fp3;
  int c;
  fp1 = fopen("group_a.txt", "a+");
  fp2 = fopen("group_b.txt", "a+");
  fp3 = fopen("group_c.txt", "a+");

  if (b >= high) {
    printf("\nEnter the power value\n");
    scanf("%d", &c);
    fprintf(fp1, "%s\t%d\t%d\n", a, b, c);

  } else if (b >= mid && b < high) {
    printf("\nEnter the power value\n");
    scanf("%d", &c);
    fprintf(fp2, "%s\t%d\t%d\n", a, b, c);
  } else {
    printf("\nEnter the power value\n");
    scanf("%d", &c);
    fprintf(fp3, "%s\t%d\t%d\n", a, b, c);
  }
}
int measure(char a[20], int b) {
  int flag = 0, priority, peek, scanner,g;
  char c[20];
  int d, f;
  FILE *fp1, *fp2, *fp3;
  fp1 = fopen("group_a.txt", "r");
  fp2 = fopen("group_b.txt", "r");
  fp3 = fopen("group_c.txt", "r");
  if (b >= high) {
    flag = read_dbms(a, fp1);
    if (flag) {
      printf("\nalready registered device\n");
    } else {
      printf("\nregister the device first\n");
      return 0;
    }
    printf("\nis it a Priority time\n");
    scanf("%d", &priority);
    printf("\nis it a peek time\n");
    scanf("%d", &peek);
    if (priority == 1) {
      rewind(fp1);
      while (fscanf(fp1, "%s%d%d", c, &d, &f) != EOF)
        if (a == c)
          break;
      g=power();
      printf("\nmeasure the data\t%d\n", g);
    } else if (peek == 1)
      printf("\nDisplay this device is not authorised at this time\n");
    else {
      rewind(fp1);
      while (fscanf(fp1, "%s%d%d", c, &d, &f) != EOF) {
        if (a == c)
          break;
      }
      g=power();
      printf("\nmeasure the data\t%d\n", g);
    }
  } else if (b >= mid && b < high) {
    flag = read_dbms(a, fp2);
    if (flag)
      printf("\nalready registered device\n");
    else {
      printf("\nregister the device first\n");
      return 0;
    }
    rewind(fp2);
    while (fscanf(fp2, "%s%d%d", c, &d, &f) != EOF)
      if (a == c)
        break;
      g=power();
      printf("\nmeasure the data\t%d\n", g);
  } else {
    flag = read_dbms(a, fp3);
    if (flag) {
      printf("\nalready registered device\n");
    } else {
      printf("\nregister the device first\n");
      return 0;
    }
    rewind(fp3);
    while (fscanf(fp3, "%s%d%d", c, &d, &f) != EOF) {
      if (a == c)
        break;
    }
    printf("\nmeasure the data\t%d\n", f);
    printf("\nthe data from the sensor\n");
    scanf("%d", &scanner);
    if (scanner >= optimal) {
      printf("\nprint the not changed power conception\n");
    } else if (scanner >= medium && scanner < optimal) {
      printf("\npower conception according to the medium condition\n");

    } else
      printf("\npower conception according to the medium condition\n");
  }
}
int main() {
  char a[20];
  int choice, b;
  do {
    printf("\nEnter your choice\n");
    printf("\n1.Register a Device \n2.measure an input\n3.exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("\nEnter the device and its capacity\n");
      scanf("%s%d", a, &b);
      printf("\n%s %d\n", a, b);
      register_device(a, b);
      break;

    case 2:
      printf("\nEnter the device and its capacity\n");
      scanf("%s%d", a, &b);
      printf("\n%s %d\n", a, b);
      measure(a, b);
      break;

    case 3:
      break;
    default:
      printf("\ninvalid choice\n");
    }

  } while (choice != 3);
  return 0;
}