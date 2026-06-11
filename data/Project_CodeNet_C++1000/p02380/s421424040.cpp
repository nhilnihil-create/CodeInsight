#include <iostream>
#include <cstdio>
#include <cmath>

#define pai 3.141592653

using namespace std;

int main(void)
{
	double a, b, C;
	double S, L, h;
	double c;

	cin >> a >> b >> C;

	h = b * sin(pai / 180 * C);
	c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(pai / 180 * C));

	S = a * h / 2;
	L = a + b + c;

	printf("%f\n", S);
	printf("%f\n", L);
	printf("%f\n", h);

	return 0;
}