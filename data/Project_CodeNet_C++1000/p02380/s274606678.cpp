#include <stdio.h>
#include <math.h>

int main(void)
{
	double a,b,c;
	double h,S,L;

	scanf("%lf %lf %lf", &a,&b,&c);
	c = (c*M_PI)/180;
	h = b*sin(c);
	S = h*a/2;
	L = a + b + sqrt(a*a + b*b - 2*a*b*cos(c));
	printf("%lf\n", S);
	printf("%lf\n", L);
	printf("%lf\n", h);
	return 0;
}

