#include<iostream>
#include<math.h>
#include<cmath>
#include <iomanip>
int main(void) {
	double a, b, c, d;
	std::cin >> a >> b >> c >> d;
	std::cout << std::fixed
		<< std::setprecision(9) <<
		std::sqrt((c - a)*(c - a) + (d - b)*(d - b))<<std::endl;
	//system("pause");
	return 0;
}