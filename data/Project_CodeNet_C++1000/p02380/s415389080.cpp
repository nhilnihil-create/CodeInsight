#define _USE_MATH_DEFINES	//M_PI
#include <iostream>			//std::cout, std::cin
#include <string>			//std::string
#include <vector>			//std::vector
#include <algorithm>		//std::sort
#include <time.h>			//localtime_s
#include <cstdlib>			//abs
#include <cmath>			//abs, pow, sqrt, sin, cos,
#include <fstream>			//std::ifstream
#include <iomanip>			//std::setprecision

int main(void) {



	int a, b, C;
	std::cin >> a >> b >> C;

	double S = a * b * sin(C*M_PI/180.0) / 2.0;
	double L = a + b + sqrt(pow(a, 2) + pow(b, 2) - (2 * a*b*cos(C*M_PI / 180.0)));
	double H = b*sin(C*M_PI / 180.0);

	std::cout << std::fixed << std::setprecision(6) << S << std::endl;
	std::cout << std::fixed << std::setprecision(6) << L << std::endl;
	std::cout << std::fixed << std::setprecision(6) << H << std::endl;

}