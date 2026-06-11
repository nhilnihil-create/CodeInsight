#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct point {
	double x;
	double y;
};

int main() {
	point p1, p2;

	cin >> p1.x >> p1.y >> p2.x >> p2.y;

	double distance = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));

	printf("%.6f\n", distance);

	return 0;
}