#include <iostream>
#include <math.h>
#include<iomanip>


using namespace std;

int main(void) {

	double a, b, c;
	double s, l, h;

	cin >> a >> b >> c;
	double z = (3.1415926535 / 180)*c;
	s = a * b * sin(z)/2.0;
	l = sqrt(a*a + b*b - (2 * a*b) * cos(z)) + a + b;
	h = 2.0 * s / a;

	cout << fixed << setprecision(5) << s << endl;
	cout << fixed << setprecision(5) << l << endl;
	cout << fixed << setprecision(5) << h << endl;
	
	return 0;
}