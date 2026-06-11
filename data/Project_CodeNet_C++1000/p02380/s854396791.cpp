#include<stdio.h>
#include<math.h>
int main(){
  double a,b,c,C,S,L,h,rad;
  scanf("%lf %lf %lf",&a,&b,&C);
  rad=M_PI*C/180.0;
  S=(1.0/2.0)*a*b*sin(rad);
  c=sqrt(a*a+b*b-2*a*b*cos(rad));
  L=a+b+c;
  h=2.0*S/a;
  printf("%f\n",S);
  printf("%f\n",L);
  printf("%f\n",h);
  return 0;
}