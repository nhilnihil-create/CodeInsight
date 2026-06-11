#include <iostream>
#include <iomanip>

int main(int argc, char const* argv[]) {
	const double PI = 3.14159265358979;
	double r;
	std::cin >> r;
	std::cout << std::fixed << std::setprecision(8);
	std::cout << r * r * PI << " " ;
	std::cout << 2 * r * PI << std::endl ;
	return 0;
}