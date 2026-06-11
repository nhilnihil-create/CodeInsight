#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	double r;
	double area, circle;

	cin >> r;

	area = r * r * 3.14159265358979323846;
	circle = 2 * r * 3.14159265358979323846;

	printf("%.6f %.6f\n", area, circle);

	return 0;
}