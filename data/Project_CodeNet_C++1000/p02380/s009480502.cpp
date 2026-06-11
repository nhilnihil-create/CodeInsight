#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double a, b, c,S,L,h;

	cin >> a >> b >> c;

	c = c * M_PI / 180;

	S = ((a * b) * sin(c)) / 2;
	L = a + b + sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(c)));
	h = b * sin(c);
	cout.precision(15);
	cout << S << endl;
	cout << L << endl;
	cout << h;

	return 0;
}