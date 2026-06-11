#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main() {
	int a, b, C;
	double S, L, h, pi, c, d;

	cin >> a >> b >> C;

	pi = acos(-1);

	d = C*pi / 180;

	c = sqrt(a*a + b*b - 2 * a*b*cos(d));

	S = 0.5*a*b*sin(d);

	L = a + b + c;

	h = b*sin(d);

	printf("%lf\n%lf\n%lf\n", S, L, h);

        return 0;
}