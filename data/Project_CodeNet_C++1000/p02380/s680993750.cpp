#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a,b,c;
	cin >> a >> b >> c;
	c = (acos(-1.0)*c)/180.0;
	double s = a*b*sin(c)/2.0;
	double l = a + b + sqrt(a*a + b*b - 2*a*b*cos(c));
	double h = b*sin(c);

	cout << fixed;
	cout.precision(6);
	cout << s << endl << l << endl << h << endl;
	return 0;
}