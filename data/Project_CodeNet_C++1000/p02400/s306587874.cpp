#include<stdio.h>
int main()
{
double r;
double a,b;
scanf("%lf",&r);
a=r*r*3.141592653589;
b=r*2*3.141592653589;
printf("%.15lf %.15lf\n",a,b);
return 0;
}