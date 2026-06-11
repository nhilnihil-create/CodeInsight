#include <stdio.h>
#define PI 3.141592653589793

int main() {
	double r, s, l;
	scanf("%lf", &r);

	s = r * r * PI;
	l = 2 * PI * r;

	printf("%f %f\n", s, l);

	return 0;
}