#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{

	double a, b, C;
	cin >> a >> b >> C;

	double S, L, h;
	double rad = C * M_PI / 180;

	S = a * b * sin(rad) / 2;
	L = sqrt(a*a + b*b - 2 * a*b*cos(rad)) + a + b;
	h = 2 * S / a;

	printf("%.4f\n", S);
    printf("%.4f\n", L);
    printf("%.4f\n", h);



    return 0;
}