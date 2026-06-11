#include<iostream>
#include<math.h>
#include<iomanip>

int main()
{
	int a, b;
	std::cin >> a >> b;

	std::cout << std::fixed << std::setprecision(6);

	int d = a / b;
	int r = a % b;
	double f = (double)a / b;

	std::cout << d << " " << r << " " << f << std::endl;
}