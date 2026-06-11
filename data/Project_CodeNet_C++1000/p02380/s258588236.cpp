#include<cstdio>
#include<cmath>

int main(void){
double a,b,C;
long double S,c,h;
scanf("%lf%lf%lf",&a,&b,&C);
C=C*3.1415926535897932384/180;
S=a*b*sin(C)*0.50;
c=sqrt(a*a+b*b-2*a*b*cos(C));
h=2*S/a;
printf("%Lf\n%Lf\n%Lf\n",S,a+b+c,h);
return 0;
}