#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

int main()
{

double a,b,C,S,H,K,k,J;
a=0;b=0;C=0;S=0;H=0;K=0;k=0;J=0;
scanf("%lf",&a);scanf("%lf",&b);scanf("%lf",&C);
C=C*(PI)/180;



H=b*sin(C);
S=0.5*a*H;
k=a*a+b*b-2*a*b*cos(C);
K=sqrt(k);
J=a+b+K;
printf("%f\n%f\n%f\n",S,J,H);
return 0;
}