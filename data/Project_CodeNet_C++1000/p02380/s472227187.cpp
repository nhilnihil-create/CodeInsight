#include <iostream>
#include <cmath>
const double pi = 3.14159265358979;
using namespace std;

double deg2rad(double degree)
{
	return degree/180*pi;
}

int main(void)
{
	double a, b, c;
	double r, s, length, h;
	
	cin >> a >> b >> r;

	r *= pi/180;
	h = b * sin(r);
	s = a * h / 2;
	c = sqrt(a*a + b*b - 2*a*b*cos(r));
	length = a + b + c;

	cout << fixed << s << " " << length << " " << h << endl;
	return 0;
}