#include<stdio.h>
#include<math.h>
#include<float.h>

int main(){
  double a,b,C,S,L,h,c,x,y;
  scanf("%lf %lf %lf",&a,&b,&C);
  x = sin(C*M_PI/180);
  y = cos(C*M_PI/180);
  S = a * b * x / 2;
  L = a + b + sqrt(a*a+b*b-2*a*b*y);
  h = 2*S/a;
  printf("%lf\n%lf\n%lf\n",S,L,h);
  return 0;
}