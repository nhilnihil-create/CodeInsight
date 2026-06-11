#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

enum {
	x,
	y,
};

void kochCurve(int n, double p1[], double p2[])
{
	if (n == 0) return;
	double s[2], t[2], ts[2], u[2];
	s[x] = (2 * p1[x] + p2[x]) / 3;
	s[y] = (2 * p1[y] + p2[y]) / 3;
	t[x] = (p1[x] + 2 * p2[x]) / 3;
	t[y] = (p1[y] + 2 *p2[y]) / 3;
	ts[x] = t[x] - s[x];
	ts[y] = t[y] - s[y];
	u[x] = s[x] + ts[x] * cos(M_PI / 180 * 60) - ts[y] * sin(M_PI / 180 * 60);
	u[y] = s[y] + ts[x] * sin(M_PI / 180 * 60) + ts[y] * cos(M_PI / 180 * 60);
	kochCurve(n - 1, p1, s);
	cout << s[x] << " " << s[y] << endl;
	kochCurve(n - 1, s, u);
	cout << u[x] << " " << u[y] << endl;
	kochCurve(n - 1, u, t);
	cout << t[x] << " " << t[y] << endl;
	kochCurve(n - 1, t, p2);
}

int main() {
	int n;
	cin >> n;
	double p1[2] = { 0, 0 };
	double p2[2] = { 100, 0 };
	cout << fixed << setprecision(8);
	cout << p1[x] << " " << p1[y] << endl;
	kochCurve(n, p1, p2);
	cout << p2[x] << " " << p2[y] << endl;
	return 0;
}
