#include<iostream>
#include<stdio.h>
using namespace std;

#define Pi 3.141592653589

int main()
{
	double r = 0.0;
	cin >> r;
	printf("%lf %lf\n", r * r * Pi, 2 * r * Pi);
	return 0;
}