#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.14159265358979
#define deg(x) (x/180.*PI)

int main(int argc, char const* argv[])
{
	double a,b,c;
	unsigned degc;
	std::cin >> a >> b >> degc;

	auto radc = deg(degc);
	auto b_h = a * std::sin(radc);
	auto s = b_h * b / 2.;

	c = std::sqrt(std::pow((b - a * std::cos(radc)), 2) + std::pow(b_h, 2));

	auto h = std::sin(radc) * b;

	std::cout << std::setprecision(6) << std::fixed;
	std::cout << s << std::endl;
	std::cout << a + b + c << std::endl;
	std::cout << h << std::endl;


	return 0;
}