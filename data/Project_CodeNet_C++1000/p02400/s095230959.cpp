#include<iostream>
#include<stdio.h>

#define PI 3.14159265358979

using namespace std;

int main() {
	double r;
	double s, l;

	cin >> r;

	s = r*r*PI;
	l = 2 * r*PI;

	printf("%f %f\n", s, l);

	return 0;
}