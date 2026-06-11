#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{	
	double const pi = 3.14159265358;
	int a,b;double rad;
	std::cin >> a >> b >> rad;
	rad = rad*pi/180;
	double s,h,l;
	s = a * b * std::sin(rad)/2;
	h = b * std::sin(rad);
	l = a + b + std::sqrt( a*a + b*b - 2 * a * b * std::cos(rad));
	printf("%lf\n%lf\n%lf\n",s,l,h);
	return 0;
}