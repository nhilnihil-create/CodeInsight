#include<iostream>
#include<math.h>
#include<iomanip>

int main()
{
	const double pi = 3.141592653589;
	double r;
	std::cin >> r;

	std::cout << std::fixed << std::setprecision(6) << r * r * pi << " " << r * pi * 2.0 << std::endl;
}