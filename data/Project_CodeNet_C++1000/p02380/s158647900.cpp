#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
	double a, b, c, C, S, L, h;
	cin >> a >> b >> C;

	C = C*2*3.14159265359 / 360;
	c = sqrt(a*a + b*b - 2 * a*b*cos(C));
	S = a*b*sin(C) / 2;
	L = a + b + c;
	h = 2 * S / a;

	printf("%f %f %f\n", S, L, h);
}