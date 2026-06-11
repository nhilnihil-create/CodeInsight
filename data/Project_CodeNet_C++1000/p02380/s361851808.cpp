#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	const double PI = acos(-1);
	double a, b, C, rad;
	cin >> a >> b >> C;
	rad = C * PI / 180;
	cout << fixed;
	cout << setprecision(6) << a*b*sin(rad) / 2 << endl << a + b + sqrt(a*a + b*b - 2 * a*b*cos(rad)) << endl << a*b*sin(rad) / a << endl;
	return 0;
}
