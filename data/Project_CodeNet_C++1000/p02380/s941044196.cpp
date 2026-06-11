#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#define rad(r) (r * M_PI / 180)
int main() {
	int a, b, C;
	scanf("%d %d %d", &a, &b, &C);
	printf("%f\n", 0.5 * a * b * sin(rad(C)));
	printf("%f\n", a + b + sqrt(a*a + b*b - 2 * a*b*cos(rad(C))));
	printf("%f\n", b * sin(rad(C)));
}