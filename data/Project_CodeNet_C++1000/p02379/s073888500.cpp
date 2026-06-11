#include <iostream>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

class Point
{
public:
	double x, y;
};

void solve()
{
	Point P1, P2;
	cin >> P1.x >> P1.y >> P2.x >> P2.y;
	printf("%.6f\n", sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y)));
}

int main()
{
	solve();
	return(0);
}