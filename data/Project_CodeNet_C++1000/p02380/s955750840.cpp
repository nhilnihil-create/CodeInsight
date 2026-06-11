#include <cstdio>
#include <cmath>

int main(){
	double a, b, C;
	scanf("%lf %lf %lf", &a, &b, &C);
	double ra = C * M_PI / 180;
	double h = sin(ra) * b;
	double S = h * a / 2;
	double L1 = a*a + b*b -2*a*b*cos(ra);
	double L = a + b + sqrt(L1);
	printf("%f\n%f\n%f\n", S, L, h);
	return 0;
}