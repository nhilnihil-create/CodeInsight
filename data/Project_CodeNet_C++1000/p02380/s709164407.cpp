#include<iostream>
#include<cmath>
#include<iomanip>
#define PI 3.14159265359
using namespace std;

int main() {
	double a, b, c, s, l, h;
	cin >> a >> b >> c;
	c = c * PI / 180;
	h = b * sin(c);
	s = a * h / 2;
	l = a + b + sqrt(a * a + b * b - 2 * a * b * cos(c));
	cout << setprecision(10) << s << endl << l << endl << h << endl;
	return 0;
}