#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
	int a, b, degc;
	double s, l, h, c, theta, pi = 3.141592653589793;
	cin >> a >> b >> degc;
	theta = (degc / 360.0) * 2.0 * pi;
	s = a*b*sin(theta) / 2.0;
	c = sqrt(a*a + b*b - 2.0 * a*b*cos(theta));
	l = a + b + c;
	h = b * sin(theta);
	cout << fixed << setprecision(6) << s << endl << l << endl << h << endl;
	return 0;
}