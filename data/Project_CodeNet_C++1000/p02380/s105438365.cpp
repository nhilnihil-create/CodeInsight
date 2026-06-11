#include <stdio.h>
#include <math.h>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	double a, b;
	a = (double)A;
	b = (double)B;
	double pi = 3.1415926535897932384626;
	double deg_to_rad = pi / 180.0;
	double c = deg_to_rad * (double)C;

	// S
	double S = 0.5 * a * b * sin(c);

	double sin_c = sin(c);
	double cos_c = cos(c);

	// h
	double h = b * sin_c;

	double l = sqrt(b * b * sin_c * sin_c + b * b * cos_c * cos_c - 2.0 * a * b * cos_c + a * a);

	// L
	double L = a + b + l;
	printf("%lf %lf %lf", S, L, h);
	return 0;
}