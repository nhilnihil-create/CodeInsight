#include<stdio.h>
#include <math.h>
#define PI 3.141592653589793

int main()
{
	double a=0,b=0,C=0;
	double unname,rad;
	double S,L,h;

	scanf("%lf %lf %lf",&a,&b,&C);
	rad = C*PI/180.0;

	S=0.5*a*b*sin(rad);
	
	unname=(a*a)+(b*b)-(2*a*b*cos(rad));
	L=a+b+sqrt(unname);

	h=b*sin(rad);

	printf("%.8lf\n %.8lf\n %.8lf\n",S,L,h);

	return 0;
}