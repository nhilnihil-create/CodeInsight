
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>

using namespace std;

int n;
const double th = M_PI * 60.0 / 180.0;
double cos60, sin60;

void printPair(pair<double, double> p) {
	cout << fixed << setprecision(8) << p.first << " " << p.second << endl;
}
void koch(int d, pair<double, double> p1, pair<double, double> p2) {
	if (d == 0) return;
	pair<double, double> s = pair<double, double>((2.0 * p1.first + 1.0 * p2.first) / 3.0, (2.0 * p1.second + 1.0 * p2.second) / 3.0);
	pair<double, double> t = pair<double, double>((1.0 * p1.first + 2.0 * p2.first) / 3.0, (1.0 * p1.second + 2.0 * p2.second) / 3.0);
	pair<double, double> u = pair<double, double>((t.first - s.first) * cos60 - (t.second - s.second) * sin60 + s.first, (t.first - s.first) * sin60 + (t.second - s.second) * cos60 + s.second);

	koch(d-1, p1, s);
	printPair(s);

	koch(d-1, s, u);
	printPair(u);

	koch(d-1, u, t);
	printPair(t);

	koch(d-1, t, p2);
}
int main()
{
	cos60 = cos(th);
	sin60 = sin(th);
	cin >> n;
	pair<double, double> p1 = pair<double, double>(0, 0);
	pair<double, double> p2 = pair<double, double>(100, 0);
	printPair(p1);
	koch(n, p1, p2);
	printPair(p2);

	return 0;
}