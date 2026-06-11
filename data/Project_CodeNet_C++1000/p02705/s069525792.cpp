#include <iostream>
#include <iomanip>

int main()
{
	double r;
    std::cin >> r;
    std::cout <<
      	std::setprecision(17) << r * 6.28318530717958623200 << std::endl;
	return 0; 
}