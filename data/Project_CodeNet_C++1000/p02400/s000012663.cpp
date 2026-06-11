#define _USE_MATH_DEFINES
#include<cstdio>
#include<cmath>

int main() {
	double r;
	scanf("%lf", &r);
	printf("%lf %lf\n", pow(r, 2)*M_PI, 2 * r*M_PI);
}
