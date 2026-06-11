#include<stdio.h>
int main( ){
  int a,b,c,d;
  double e;
  scanf("%d %d",&a,&b);
  c=a/b;
  d=a%b;
  e=(double)a/b;
  printf("%d %d %f\n",c,d,e);
  return 0;
}