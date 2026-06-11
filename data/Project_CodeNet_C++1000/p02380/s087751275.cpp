#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
using namespace std;

#define B

#ifdef B
static const double PI = 3.141592653589793; 
double ST_PI = PI / 180;

int main(void) {
	double a, b, c, ab, s, l, h;
	cin >> a >> b >> ab;

	s = a * b * sin(ST_PI * ab) * 0.5;

	l = sqrt(a*a + b*b - 2 * a*b*cos(ST_PI * ab)) + a + b;

	h = b * sin(ST_PI * ab);

	cout << fixed << setprecision(12) << s << endl;
	cout << fixed << setprecision(12) << l << endl;
	cout << fixed << setprecision(12) << h << endl;

	return 0;
}
#endif // B