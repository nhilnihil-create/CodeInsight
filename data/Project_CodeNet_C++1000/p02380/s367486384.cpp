#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#define rad(r) (r * M_PI / 180)
int main() {
	double a, b, C, S;
	scanf("%lf %lf %lf", &a, &b, &C);
	S = 0.5 * a * b * sin(rad(C));
	printf("%f\n", S);
	printf("%f\n", a + b + sqrt(a*a + b*b - 2 * a*b*cos(rad(C))));
	printf("%f\n", 2 * S / a);
}