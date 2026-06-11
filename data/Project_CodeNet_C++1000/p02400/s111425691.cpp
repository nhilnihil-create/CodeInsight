#include <iostream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(){
	double r;
	cin >> r;

	double area = r * r * M_PI;
	double circle = 2 * r * M_PI;

	printf("%lf %lf", area, circle);

}