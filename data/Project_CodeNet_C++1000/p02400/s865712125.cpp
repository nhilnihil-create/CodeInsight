#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>


int main(int argc, char **argv){
	double r = 0;

	std::cin >> r;

	std::cout << std::fixed << std::setprecision(7)
		<< M_PI * r * r << " "
		<< 2 * r * M_PI << std::endl;

	return 0;
}