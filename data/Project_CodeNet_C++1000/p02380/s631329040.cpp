#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

# define PI 3.14159265359

int main() {
	long double a, b, c;

	cin >> a >> b >> c;
	c *= (PI/180);

	cout << fixed << setprecision(10);
	cout << (1.0 / 2.0) * a * b * sin( c ) << endl;
	cout << a + b + sqrt( pow(a, 2) + pow(b, 2) - 2.0 * a * b * cos( c ) ) << endl;
	cout << b * sin( c ) << endl;

	return 0;
}