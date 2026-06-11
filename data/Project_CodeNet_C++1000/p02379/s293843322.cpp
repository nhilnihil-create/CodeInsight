#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
	double x1, y1, x2, y2, distance, height, length;

	cin >> x1 >> y1 >> x2 >> y2;

	height = (double)y2 - y1;
	length = (double)x2 - x1;

	distance = sqrt(height * height + length * length);

	printf("%lf", distance);

	return 0;
}
