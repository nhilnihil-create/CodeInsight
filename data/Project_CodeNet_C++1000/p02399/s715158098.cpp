#include<stdio.h>

int main(){
  long a,b,c,d;
  scanf("%ld %ld",&a,&b);
  if(1<=a && a<=1000000000 && 1<=b && b<=1000000000){
  c = a	/ b;
  d = a	% b;
  double f = a;
  double g = b;
  double e = f / g;
  printf("%ld %ld %.5lf\n",c,d,e);
  }
  return 0;
}