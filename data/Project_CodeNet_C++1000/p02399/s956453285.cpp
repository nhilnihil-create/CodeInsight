#include<stdio.h>

int main(){
  int a,b,d,r;
  scanf("%d %d",&a,&b);
  if(1<=a && a<=1000000000 && 1<=b && b<=1000000000){
  d = a	/ b;
  r = a	% b;
  double x = a;
  double y = b;
  double f = x / y;
  printf("%d %d %.5lf\n",d,r,f);
  }
  return 0;
}