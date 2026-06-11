#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define PI 3.14159265359

int main() {
	double a, b, c, s, C, S;
	cin >> a >> b >> C;
	c = sqrt(a*a + b*b - 2*a*b * cos(C*PI/180.0));
	s = (a + b + c) / 2.0;
	S = sqrt(s*(s-a)*(s-b)*(s-c));
	cout << fixed << setprecision(6) << S << ' ' << a + b + c << ' ' << S*2.0 / a << endl;
	return 0;
}