#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
 
int main() {
	double a, b, C;
	cin >> a; cin >> b; cin >> C;
	double S, L, h;
	S = a * b * sin(C * M_PI / 180.0) / 2.0;
	L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(C * M_PI / 180.0));
	h = 2.0 * S / a;
	cout << setprecision(10) << S << endl;
	cout << L << endl;
	cout << h << endl;
	return 0;
}