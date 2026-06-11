#define _USE_MATH_DEFINES

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	double a, b, c;

	double S, L, h;

	cin >> a >> b >> c;

	S = 0.5*a*b*sin(c*M_PI/180);

	L = a + b + sqrt((a*a) + (b*b) - (2 * a*b*cos(c*M_PI / 180)));

	h = b*sin(c*M_PI/180);

	printf("%lf\n%lf\n%lf\n", S, L, h);

	return 0;
}