#define _USE_MATH_DEFINES

#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	double a, b, angleC;
	scanf("%lf %lf %lf", &a, &b, &angleC);
	angleC = angleC * M_PI / 180;
	double h = b * sin(angleC);
	double S = a * h / 2;
	double L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(angleC));
	printf("%.8lf %.8lf %.8lf", S, L, h);

	return 0;
}