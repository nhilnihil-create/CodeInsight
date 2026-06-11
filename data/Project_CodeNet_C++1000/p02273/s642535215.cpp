#include <iostream>
#include <cmath>

using namespace std;

int n;
double sin60, cos60;

void fractal(double x1, double y1, double x2, double y2, int d) {
	if (d == n) {
		cout << x2 << " " << y2 << endl;
		return;
	}
	
	double sx, sy, tx, ty, ux, uy;
	sx = (2 * x1 + x2) / 3;
	sy = (2 * y1 + y2) / 3;
	tx = (x1 + 2 * x2) / 3;
	ty = (y1 + 2 * y2) / 3;
	ux = (tx - sx) * cos60 - (ty - sy) * sin60 + sx;
	uy = (tx - sx) * sin60 + (ty - sy) * cos60 + sy;

	fractal(x1, y1, sx, sy, d + 1);
	fractal(sx, sy, ux, uy, d + 1);
	fractal(ux, uy, tx, ty, d + 1);
	fractal(tx, ty, x2, y2, d + 1);
}

int main() {
	sin60 = sin(M_PI / 3);
	cos60 = cos(M_PI / 3);
	cin >> n;

	cout << "0 0" << endl;
	fractal(0, 0, 100, 0, 0);

	return 0;
}