#include<stdio.h>
#include<string.h>
#include <math.h>
int main(void)
{
	double a,s,d,f,g,h,i,j,z;
	scanf("%lf %lf %lf %lf",&a,&s,&d,&f);
	h=s-f;
	g=a-d;
	z=sqrt(h*h+g*g);
	printf("%lf\n",z);
	return 0;
}