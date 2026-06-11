#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, c, degc, radc;
	double s, r, l, h;
	double pi = 4 * atan( 1.0 );

	cin >> a >> b >> degc;
	radc = degc * pi / 180.0;
	s = b * a * sin( radc ) / 2.0;
	c = sqrt( a*a + b*b - 2*a*b*cos( radc ) );
	r = c / ( 2.0 * sin( radc ) );
	l = 2.0 * r * pi; /* circumference */

	l = a + b + c;
	h = b * sin( radc );

	cout << fixed << s << endl << l << endl << h << endl;
	return 0;
}