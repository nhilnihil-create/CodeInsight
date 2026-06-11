#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define PI 3.14159265358979

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	printf("%.5f\n", a * b * sin(c * PI / 180) * 0.5);
	printf("%.5f\n", a + b + sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(c * PI / 180))));
	printf("%.5f\n", b * sin(c * PI / 180));
	return 0;
}