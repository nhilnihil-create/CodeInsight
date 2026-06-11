#include <math.h>
#include <iostream>
#include <iomanip>

#define PI 3.14159265358979
#define DEG_TO_RAD(deg) (((deg) / 180 ) * PI)

using namespace std;

int main()
{
	double a, b, C;
	double S, L, h;
	double c;
	cin >> a >> b >> C;
	c = sqrt((a * a) + (b * b) - (2 * a * b * cos(DEG_TO_RAD(C))));
	S = a * b * sin(DEG_TO_RAD(C)) / 2;
	L = a + b + c;
	h = b * sin(DEG_TO_RAD(C));
	cout << fixed
		<< setprecision(8)
		<< S << endl
		<< L << endl
		<< h << endl;
	return 0;
}