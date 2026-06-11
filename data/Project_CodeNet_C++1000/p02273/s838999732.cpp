#define scanf_s scanf

#include <string>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <iostream>
using namespace std;
#define PI 3.14159265358
#define _rag(x) (x) * (PI / 180)
void fractale(int n, double p1x, double p1y, double p2x, double p2y)
{
	if (n > 0) {
		double sx = 0, sy = 0, ux = 0, uy = 0, tx = 0, ty = 0;
		sx = (2 * p1x + p2x) / 3; sy = (2 * p1y + p2y) / 3;
		tx = (p1x + 2 * p2x) / 3; ty = (p1y + 2 * p2y) / 3;
		ux = (tx - sx) * cos(_rag(60.0)) - (ty - sy) * sin(_rag(60.0)) + sx;
		uy = (tx - sx) * sin(_rag(60.0)) + (ty - sy) * cos(_rag(60.0)) + sy;

		fractale(n - 1, p1x, p1y, sx, sy);//1
		printf("%f %f\n", sx, sy);

		fractale(n - 1, sx, sy, ux, uy);//2
		printf("%f %f\n", ux, uy);

		fractale(n - 1, ux, uy, tx, ty);//3
		printf("%f %f\n", tx, ty);
		fractale(n - 1, tx, ty, p2x, p2y);//4	
	}
}
int main(void)
{
	int n;
	scanf_s("%d", &n);
	printf("%f %f\n", 0.0, 0.0);
	fractale(n, 0.0, 0.0, 100.0, 0.0);
	printf("%f %f\n", 100.0, 0.0);

}