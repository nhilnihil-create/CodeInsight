#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a, b, C;
	cin >> a >> b >> C;

	C *= M_PI / 180.0;
	double h = b * sin(C);
	double c = sqrt(a*a + b*b - 2.0*a*b*cos(C));

	cout << fixed << setprecision(4);
	cout << 0.5*a*h << ' ';
	cout << a+b+c << ' ';
	cout << h << endl;

	return 0;
}

