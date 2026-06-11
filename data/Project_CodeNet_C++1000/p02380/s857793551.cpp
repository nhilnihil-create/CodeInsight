#include<iostream>
#include <math.h>
#include <iomanip>

using namespace std;
#define PIE 3.14159265358979
int main() {
	long double a, b, c,S,L,H;
	cin >> a >> b >> c;
	S = a*b*sin(c / 180 * PIE) / 2;
	L = a + b + sqrt(a*a + b*b - 2 * a*b*cos(c / 180 * PIE));
	H= b*sin(c / 180 * PIE);
	cout << fixed << setprecision(8) << S << endl << L << endl << H << endl;
	return 0;
}