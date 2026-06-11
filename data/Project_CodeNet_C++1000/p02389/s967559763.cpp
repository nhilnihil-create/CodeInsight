#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

double line_func(double x, double y) {
	return 2*(x+y);
}

double square_func(double x, double y) {
	return x*y;
}

int main() 
{
	double a, b;
	cin >> a >> b ;
	cout << square_func(a, b) << " " << line_func(a, b) << endl;
}