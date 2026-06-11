#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;


int main()
{
	double a, b, c, d, PI, S, L, h;
	cin >> a >> b >> c;
	PI = acos(-1);
	S = (a*b*sin(c * (2.00000 * PI)/360.00000))/2.0000;
	d = sqrt(a*a + b * b - 2.000000 * a*b*cos(c * 2.000000 * PI / 360.00000));
	L = a + b + d;
	h = 2.0000000 * S / a;
	printf("%.8lf\n", S);
	printf("%.8lf\n", L);
	printf("%.8lf\n", h);
    return 0;
}

