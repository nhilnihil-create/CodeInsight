#include <iostream>
#include <cmath>
using namespace std;
double pi(void)
{
	return atan(1.0) * 4;
}
double deg2rad(double degree)
{
	return degree/180*pi();
}

int main(void)
{
	double a, b, c;
	double r, s, length, h;

	cin >> a >> b >> r;
	r = deg2rad(r);
	h = b * sin(r);
	s = a * h / 2;
	c = sqrt(a*a + b*b - 2*a*b*cos(r));
	length = a + b + c;
	cout << fixed << s << " " << length << " " << h << endl;
	return 0;
}