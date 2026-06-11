#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a, b, C;
	cin >> a >> b >> C;

	double sgn = (C>90) ? -1.0 : 1.0;
	double sinC = sin(M_PI * C / 180.0);
	double h = b * sinC;
	double c = sqrt(a*a + b*b - 2.0*sgn*a*b*sqrt(1-sinC*sinC));

	cout << fixed << setprecision(4);
	cout << 0.5*a*h << ' ';
	cout << a+b+c << ' ';
	cout << h << endl;

	return 0;
}

