#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

int main() {
	double a, b, C;			// ??\???
	double S, L, h, x, c;	// ??????

	// ??\???
	cin >> a >> b >> C;

	C = (C*M_PI) /180;
	h = b*sin(C);

	S = a * h / 2;

	x = b * cos(C);
	c = sqrt(pow(h, 2.0) + pow((a-x), 2.0));
	L = a + b + c;

	// ??????
	cout << std::fixed << std::setprecision(10) << S << endl;
	cout << std::fixed << std::setprecision(10) << L << endl;
	cout << std::fixed << std::setprecision(10) << h << endl;

	return 0;
}