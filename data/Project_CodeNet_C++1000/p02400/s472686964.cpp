#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>

int main()
{
	double r;
	std::cin >> r;	
	
	std::cout << std::fixed << std::setprecision(6) << r * r * M_PI << " ";
	std::cout << std::fixed << std::setprecision(6) << r * 2 * M_PI << std::endl;

}