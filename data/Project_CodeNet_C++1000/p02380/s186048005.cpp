
#include<iostream>
#include<iomanip>
#include<cmath>

#define PI 3.1415926

using namespace std;

int main(){

	double a, b, c, s, l, h;

	cin >> a >> b >> c;

	c = c * PI / 180;

	s = a * b * sin(c) / 2.0;

	h = s * 2.0 / a;

	l = sqrt(pow(a, 2) + pow(b, 2) - 2.0 * a * b * cos(c)) + a + b;

		cout << setprecision(8) << s << endl << l << endl << h << endl;

	return 0;
}
