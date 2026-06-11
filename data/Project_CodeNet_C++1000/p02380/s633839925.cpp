#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	double h =  b *sin((c *  M_PI )/ 180);
	cout << fixed << (a * h) / 2 << endl;
	cout << a + b + sqrt(a * a + b * b - 2 * a * b * cos((c * M_PI)/180)) << endl;
	cout << h << endl;

	return 0;
}