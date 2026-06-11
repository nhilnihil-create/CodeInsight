#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI (3.1415926535898)

int main(void) {

	double a, b, C, rad;
	double S, L, h;

	scanf("%lf %lf %lf", &a, &b, &C);

	rad = C * PI / 180.0;

	h = b * sin(rad);
	S = a * h / 2.0;
	L = a + b + sqrt((h * h) + ( (a - b * cos(rad)) * (a - b * cos(rad))));


	printf("%10.8lf\n", S);
	printf("%10.8lf\n", L);
	printf("%10.8lf\n", h);

}