#include <stdio.h>
#include <math.h>
int main(){
  double a,b,C,Cd,c2,c,S,L,h,pi;
  scanf("%lf%lf%lf",&a,&b,&C);
  pi=acos(-1);
  Cd=C*pi/180;
  S=0.5*a*b*sin(Cd);
  c2=a*a+b*b-2*a*b*cos(Cd);
  c=sqrt(c2);
  L=a+b+c;
  h=(2*S)/a;
  printf("%.8f\n",S);
  printf("%.8f\n",L);
  printf("%.8f\n",h);
  return 0;
}