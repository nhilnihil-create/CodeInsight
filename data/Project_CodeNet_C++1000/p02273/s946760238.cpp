#define _USE_MATH_DEFINES;
#include <math.h>
#include <cstdio>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

void Koch(double p1x, double p1y, double p2x, double p2y, int n)
{
	if (n <= 0)return;
	double sx = (2.0 * p1x + 1.0 * p2x) / 3.0;
	double sy = (2.0 * p1y + 1.0 * p2y) / 3.0;
	double tx = (1.0 * p1x + 2.0 * p2x) / 3.0;
	double ty = (1.0 * p1y + 2.0 * p2y) / 3.0;
	double ux = (tx - sx) * cos(M_PI* 60.0 / 180.0) - (ty - sy) * sin(M_PI * 60.0 / 180.0) + sx;
	double uy = (tx - sx) * sin(M_PI * 60.0 / 180.0) + (ty - sy) * cos(M_PI * 60.0 / 180.0) + sy;
	Koch(p1x, p1y, sx, sy, n - 1);
	printf("%.8f %.8f\n", sx, sy);
	Koch(sx, sy, ux, uy, n - 1);
	printf("%.8f %.8f\n", ux, uy);
	Koch(ux, uy, tx, ty, n - 1);
	printf("%.8f %.8f\n", tx, ty);
	Koch(tx, ty, p2x, p2y, n - 1);

}
void C()
{
	int N = 0;
	scanf("%d", &N);
	printf("%.8f %.8f\n",0.0,0.0);
	Koch(0, 0, 100, 0, N);
	printf("%.8f %.8f\n", 100.0, 0.0);

}

int main()
{
	C();
	return 0;
}