#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c;
	double s, l, h;
	cin >> a >> b >> c;
	s = a * b * sin(c * M_PI / 180.0) / 2.0;
	l = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(c * M_PI / 180.0));
	h = s / a * 2;
	cout << fixed << setprecision(5) << s << endl;
	cout << fixed << setprecision(5) << l << endl;
	cout << fixed << setprecision(5) << h << endl;
}
