#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;


int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	double dA, dC, dH, dD;
	c *= M_PI / 180;
	dA = (a*b*sin(c)) / 2.0;
	dD = sqrt(a*a + b * b - 2 * a*b * cos(c));
	dC = a + b + dD;
	dH = dA * 2 / a;
	printf("%.5lf\n", dA);
	printf("%.5lf\n", dC);
	printf("%.5lf\n", dH);

	//system("pause");
	return 0;
}