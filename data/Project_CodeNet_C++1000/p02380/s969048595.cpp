#include <iostream>
#include <iomanip>
#include <math.h>
#define PI 3.14159265358979323846

using namespace std;
int main()
{
	double a, b, c, s, t, r, h;
	cin >> a >> b >> c;
	c = c / 180.0 * PI;
	s = sin( c );
	t = cos( c );
	r = sqrt( a*a + b*b - 2*a*b*t );
	h = b * s;
	cout << fixed << setprecision(5) << 0.5 * a * h << "\n";
	cout << fixed << setprecision(5) << a + b + r << "\n";
	cout << fixed << setprecision(5) << h << "\n";

	return 0;
}