#include <iostream>
#include <cstdio>
#include <cmath>

#define PI 3.14159265358979323

using namespace std;

int main() {
	double a, b, C;
	double S, L, h;
	cin >> a >> b >> C;
	double rad = C * PI / 180.0;
	S = 0.5 * a * b * sin(rad);
	L = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(rad));
	h = b * sin(rad);
	printf("%.8f\n", S);
	printf("%.8f\n", L);
	printf("%.8f\n", h);
	return 0;
}