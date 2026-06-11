#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	int a, b, C;
	double S, L, h, r, p = 3.141592653589793;

	cin >> a >> b >> C;

	r = C * p / 180.0;
	S = (a * b * sin(r)) / 2;
	L = a + b + sqrt((a * a) + (b * b) - (2 * a * b * cos(r)));
	h = b * sin(r);

	cout << fixed << S << endl << L << endl << h << endl;

	return 0;
}