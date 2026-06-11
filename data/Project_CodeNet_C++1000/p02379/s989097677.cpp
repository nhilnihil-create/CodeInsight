#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    double x;
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	x = ((c - a) * (c - a)) + ((d - b) * (d - b));
	printf("%.6f \n", sqrt(x));
}

