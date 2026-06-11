#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main(void)
{
	double r;

	scanf("%lf", &r);

	printf("%f %f",r*r*M_PI,2 * r*M_PI);

	return 0;
}