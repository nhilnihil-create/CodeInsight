#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<list>
#define _USE_MATH_DEFINES

#include<math.h>
#include<map>

#define SENTINEL 1000000001

#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int counter = 0;

void KochCurve(int state, int n, double sx, double sy, double ex, double ey)
{
	double x2, y2, x3, y3, x4, y4;
	double angle = atan2((ey - sy), (ex - sx)) + M_PI / 3.0;
	double length = sqrt((sx - ex)*(sx - ex) + (sy - ey)*(sy - ey)) / 3.0;
	x2 = sx + (ex - sx) / 3.0;
	y2 = sy + (ey - sy) / 3.0;
	x3 = x2 + cos(angle)*length;
	y3 = y2 + sin(angle)*length;
	x4 = sx + (ex - sx) / 3.0*2.0;
	y4 = sy + (ey - sy) / 3.0*2.0;

	if (state < n)KochCurve(state + 1, n, sx, sy, x2, y2);
	printf("%lf %lf\n", x2, y2);
	if (state < n)KochCurve(state + 1, n, x2, y2, x3, y3);
	printf("%lf %lf\n", x3, y3);
	if (state < n)KochCurve(state + 1, n, x3, y3, x4, y4);
	printf("%lf %lf\n", x4, y4);
	if (state < n)KochCurve(state + 1, n, x4, y4, ex, ey);
}

int main()
{
	int n;
	double sx = 0.0, sy = 0.0, ex = 100.0, ey = 0.0;
	scanf("%d", &n);

	printf("%lf %lf\n", sx, sy);

	if (n > 0)KochCurve(1, n, sx, sy, ex, ey);

	printf("%lf %lf\n", ex, ey);

	return 0;
}
