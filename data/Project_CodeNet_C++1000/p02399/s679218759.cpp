#include <iostream>
#include <iomanip>

int main()
{
	int a, b;
	std::cin >> a >> b;

	int d = a / b;
	int r = a % b;
	double f = static_cast<double>(a) / b;

	std::cout << d << " " << r << " " << std::fixed << std::setprecision(5) << f << std::endl;
}