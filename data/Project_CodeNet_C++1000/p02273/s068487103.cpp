#include <cmath>
#include <iostream>
#define PI 3.1415926535897932384626433832795028842L
using namespace std;
void solve(long double xa, long double ya, long double xb, long double yb, int d) {
	if (!d) return;
	long double xc = (xa * 2 + xb) / 3;
	long double yc = (ya * 2 + yb) / 3;
	long double xe = (xa + xb * 2) / 3;
	long double ye = (ya + yb * 2) / 3;
	long double xd = (xe - xc) * cos(PI / 3) - (ye - yc) * sin(PI / 3) + xc;
	long double yd = (xe - xc) * sin(PI / 3) + (ye - yc) * cos(PI / 3) + yc;
	solve(xa, ya, xc, yc, d - 1);
	printf("%.20Lf %.20Lf\n", xc, yc);
	solve(xc, yc, xd, yd, d - 1);
	printf("%.20Lf %.20Lf\n", xd, yd);
	solve(xd, yd, xe, ye, d - 1);
	printf("%.20Lf %.20Lf\n", xe, ye);
	solve(xe, ye, xb, yb, d - 1);
}
int n;
int main() {
	cin >> n;
	printf("%.20Lf %.20Lf\n", 0.0L, 0.0L);
	solve(0.0, 0.0, 100.0, 0.0, n);
	printf("%.20Lf %.20Lf\n", 100.0L, 0.0L);
	return 0;
}