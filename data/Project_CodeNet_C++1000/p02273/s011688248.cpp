#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265;
int n;

void koch(double p1[2], double p2[2], int i) {
	if (i == n) return;
	double s[2], t[2], u[2];
	s[0] = (2 * p1[0] + p2[0]) / 3;
	s[1] = (2 * p1[1] + p2[1]) / 3;
	t[0] = (p1[0] + 2 * p2[0]) / 3;
	t[1] = (p1[1] + 2 * p2[1]) / 3;
	u[0] = (t[0] - s[0]) * cos(PI / 3) - (t[1] - s[1]) * sin(PI / 3) + s[0];
	u[1] = (t[0] - s[0]) * sin(PI / 3) + (t[1] - s[1]) * cos(PI / 3) + s[1];

	koch(p1, s, i + 1);
	cout << s[0] << " " << s[1] << endl;
	koch(s, u, i + 1);
	cout << u[0] << " " << u[1] << endl;
	koch(u, t, i + 1);
	cout << t[0] << " " << t[1] << endl;
	koch(t, p2, i + 1);
}

int main() {
	cin >> n;
	double p1[2] = { 0, 0 }, p2[2] = { 100, 0 };
	cout << p1[0] << " " << p1[1] << endl;
	koch(p1, p2, 0);
	cout << p2[0] << " " << p2[1] << endl;
	cin >> n;
	return 0;
}