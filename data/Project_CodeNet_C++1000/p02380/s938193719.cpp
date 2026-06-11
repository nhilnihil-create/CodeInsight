#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
	int c;
	double a, b, S, L, h;
	const double PI = 3.14159265359;

	cin >> a >> b >> c;

	double radian = c * PI / 180.0;

	S = 1.0 / 2.0 * a * b * sin(radian);
	L = a + b + sqrt(a*a + b*b - 2.0*a*b*cos(radian));
	h = b * sin(radian);

	cout << fixed << setprecision(14) << S << "\n"
		<< L << "\n"
		<< h << "\n";
}