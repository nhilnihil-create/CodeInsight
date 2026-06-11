#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int a, b, C;
	double S, L, h;

	S = L = h = 0;
	cin >> a >> b >> C;

	S = 0.5 * a * b * sin((C * M_PI) / 180);
	L = a + b + sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos((C * M_PI) / 180)));
	h = (2 * S) / a;

	cout << setprecision(16) << S << endl;
	cout << L << endl;
	cout << h << endl;

	return 0;
}