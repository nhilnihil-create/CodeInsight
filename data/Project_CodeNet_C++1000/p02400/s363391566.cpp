#define _USE_MATH_DEFINES
#include <math.h>
#include<iostream>
#include <cstdio>

using namespace std;

int main() {
	double r;
	cin >> r;
	double vast, circle;
	vast = r*r*M_PI;
	circle = 2 * r*M_PI;
	printf("%.6f %.6f", vast, circle);
	return 0;
}