#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	double x1, x2, y1, y2, distance;
	cin >> x1 >> y1 >> x2 >> y2;

	distance = hypot(x2 - x1, y2 - y1);

	printf("%lf\n", distance);
	return 0;
}