#include <iostream>
#include <cmath>
using namespace std;

void solve(double lx, double ly, double rx, double ry, int depth) {
	if (depth == 0) {
		printf("%.8f %.8f\n", lx, ly);
	} else {
		double sx, sy, ux, uy, tx, ty;
		sx = (2.0 * lx + rx) / 3.0;
		sy = (2.0 * ly + ry) / 3.0;
		tx = (lx + 2.0 * rx) / 3.0;
		ty = (ly + 2.0 * ry) / 3.0;
		ux = (tx + sx - sqrt(3.0) * (ty - sy)) / 2.0;
		uy = (sqrt(3.0) * (tx - sx) + ty + sy) / 2.0;
		solve(lx, ly, sx, sy, depth - 1);
		solve(sx, sy, ux, uy, depth - 1);
		solve(ux, uy, tx, ty, depth - 1);
		solve(tx, ty, rx, ry, depth - 1);
	}
}

int main() {
	int n;
	cin >> n;
	solve(0.0, 0.0, 100.0, 0.0, n);
	printf("%.8f %.8f\n", 100.0, 0.0);
	return 0;
}
