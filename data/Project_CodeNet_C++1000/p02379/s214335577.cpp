#include <cstdio>
#include <cmath>
int main() {
	double a, b, c, d;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	printf("%f\n", sqrt(pow(c - a, 2) + pow(d - b, 2)));
}