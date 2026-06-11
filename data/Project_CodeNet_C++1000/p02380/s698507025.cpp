#include <iostream>
#include <cmath>
using namespace std;

int main()
{
		double a, b, c, C, S, L, h, rad;
		static const double pi = 3.141592653589793;
		cin >> a >> b >> C;
		rad = pi/(180/C);
		c = sqrt((a*a)+(b*b)-(2*a*b*cos(rad)));
		S = (1.0/2.0)*a*b*sin(rad);
		L = a+b+c;
		h = 2*S/a;
		cout << fixed << S << "\n";
		cout << fixed << L << "\n";
		cout << fixed << h << "\n";
}