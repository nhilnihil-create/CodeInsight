#define _USE_MATH_DEFINES
#include<iostream>
#include<math.h>
#include<cmath>
#include <iomanip>
int main(void) {
	double a, b, c;
	std::cin >> a >> b >> c;
	std::cout << std::fixed << std::setprecision(9) << 0.5*a*b*std::sin(M_PI*c / 180.) << std::endl
		<< std::fixed << std::setprecision(9) << a + b + std::sqrt(a*a + b*b - 2.*a*b*std::cos(M_PI*c / 180.)) << std::endl
		<< std::fixed << std::setprecision(9) << b* std::sin(M_PI*c / 180.) << std::endl;
	//system("pause");
	return 0;
}