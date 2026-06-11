#include<stdio.h>

int main(){
  int a,b,c,d;
  scanf("%d %d",&a,&b);
  if(1<=a && a<=1000000000 && 1<=b && b<=1000000000){
  c = a	/ b;
  d = a	% b;
  double f = a;
  double g = b;
  double e = f / g;
  printf("%d %d %.5lf\n",c,d,e);
  }
  return 0;
}