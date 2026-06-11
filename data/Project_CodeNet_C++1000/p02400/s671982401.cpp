#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double r;
	cin >> r;
	double a, c;
	a = pow(r, 2.0) * M_PI;
	c = double(2.0) * M_PI * r;
	printf("%.6f %.6f\n", a, c);
	return 0;
}