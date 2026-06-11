#include <iostream>
#include <cstdio>
#include <cmath>

#define PI 3.1415926535

using namespace std;

int main() {
	int a, b, C;

	cin >> a >> b >> C;


	double S = a*b*sin(C / 180.0 * PI) / 2;
	double L = sqrt(a*a + b*b - 2 * a*b*cos(C / 180.0 * PI)) + a + b;
	double h = 2 * S / a;

	printf("%.4f\n", S);
	printf("%.4f\n", L);
	printf("%.4f\n", h);

	return 0;
}