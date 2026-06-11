#include <iostream>
#include <iomanip>

#define PI 3.14159265359

int main(void)
{
	double r;
	std::cin >> r;
	std::cout
		<< std::fixed
		<< std::setprecision(6)
		<< r * r * PI << " "
		<< r * 2 * PI << std::endl;
	return 0;
}