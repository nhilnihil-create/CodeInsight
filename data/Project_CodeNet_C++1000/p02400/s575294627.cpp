#include<iostream>
#include <cstdio>
using namespace std;


int main()
{
	double r;
	double pi = 3.141592653589;
	cin >> r;
	double s = r * r * pi;
	double l = r * 2 * pi;
	printf("%.6lf %.6lf\n", s, l);
	return 0;
}