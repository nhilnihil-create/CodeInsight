#include <iostream>
#include <cmath>
#include <iomanip>
const double PI = acos(-1);
using namespace std;

int main(int argc, char const *argv[])
{
	double a, b, C;
	cin >> a >> b >> C;
	C = PI * C / 180;

	double s, l, h;
	s = a * b * sin(C) / 2;
	l = a + b + sqrt(a*a + b*b - 2*a*b*cos(C));
	h = 2 * s / a;

	cout << setprecision(10) << s << endl << l << endl << h << endl;
	return 0;
}