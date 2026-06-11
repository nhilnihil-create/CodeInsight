#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	const double pi = atan(1.0) * 4;
	double rad = pi*(double)c / 180.0;
	double S = 0.5*(double)a*(double)b*sin(rad);
	double L = (double)a + (double)b + sqrt(a*a + b*b - 2 * (double)a*(double)b*cos(rad));
	double h = (double)b * sin(rad);
	printf("%.5f %.5f %.5f\n", S, L, h);
	return 0;
}