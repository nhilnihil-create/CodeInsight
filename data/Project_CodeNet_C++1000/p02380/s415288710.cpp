#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
	double a, b, c, d, s, l, h;
	cin >> a >> b >> c;
	c = c * M_PI / 180;
	d = sqrt(a * a + b * b - 2 * a * b * cos(c));
	l = a + b + d;
	s = 1.0 / 2.0 * a * b * sin(c);
	h = s * 2 / a;
	printf("%.6f\n%.6f\n%.6f\n", s, l, h);
}
