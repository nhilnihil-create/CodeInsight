#include <iostream>

#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	double r;
	double s, l;
	
	cin >> r;

	s = r * r * M_PI;
	l = 2 * r* M_PI;

	printf("%f %f", s, l);
	return 0;
}