#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	double a, b, C;
	cin >> a >> b >> C;

	double S, L, h, radC, c;
	radC = C *acos(-1) / 180;
	S = 0.5 * a * b * sin(radC);
	c = sqrt(a*a + b*b - 2 * a*b*cos(radC));
	L = a + b + c;
	h = 2 * S / a;

	printf("%lf\n%lf\n%lf\n", S, L, h);

	return 0;
}

