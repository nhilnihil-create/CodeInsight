#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define PI 3.14159265358979

using namespace std;

int main()
{
	double a, b, c, d, l, s, S;
	scanf("%lf%lf%lf", &a, &b, &c);
	d = sqrt(a*a + b*b - 2.0 * a*b*cos(c/180.0*PI));
	s = (a + b + d) / 2.0;
	S = sqrt(s*(s - a)*(s - b)*(s - d));
	printf("%.10f %.10f %.10f\n", S, a+b+d, S * 2.0 / a);
    return 0;
}

