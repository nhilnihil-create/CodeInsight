#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
	double r;
	cin >> r;
	double area = r * r * M_PI;
	double length = (r*2) * M_PI;
	printf("%f %f", area, length);
}