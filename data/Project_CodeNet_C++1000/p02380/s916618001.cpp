#include<iostream>
#include<iomanip>
#define _USE_MATH_DEFINES
#include<cmath>
int main()
{
	double a, b, C;
	std::cin >> a >> b >> C;
	const double S = a * b * sin(C / 180 * M_PI) / 2;
	const double L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(C / 180 * M_PI));
	const double h = 2 * S / a;
	std::cout << std::fixed << std::setprecision(10);
	std::cout << S << std::endl;
	std::cout << L << std::endl;
	std::cout << h << std::endl;
	return 0;
}
