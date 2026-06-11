#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	double r;
	double a, b;

	cin >> r;

	a = r * r * 3.14159265358979;
	b = r * 2 * 3.14159265358979;

	printf("%.6lf %.6lf\n", a, b);

	return 0;
}