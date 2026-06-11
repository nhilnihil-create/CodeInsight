#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

int main(void) {
	int a, b, lC;
	double lS, lL, h;
	double cRad;

	scanf("%d %d %d", &a, &b, &lC);
	cRad = lC / 180.0 * M_PI;

	lS = a * b * sin(cRad) / 2;
	lL = a + b + sqrt(a * a + b * b - 2 * a * b * cos(cRad));
	h = 2 * lS / a;

	printf("%f\n%f\n%f\n", lS, lL, h);
	return 0;
}