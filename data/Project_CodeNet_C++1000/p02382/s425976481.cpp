#define _USE_MATH_DEFINES	//M_PI
#include <iostream>			//std::cout, std::cin
#include <string>			//std::string
#include <vector>			//std::vector
#include <valarray>			//std::valarray	??°????????????????¬???????
#include <algorithm>		//std::sort
#include <time.h>			//localtime_s
#include <cstdlib>			//abs
#include <cmath>			//abs, pow, sqrt, sin, cos,
#include <fstream>			//std::ifstream
#include <iomanip>			//std::setprecision

int main(void) {

	//test??¨
	//std::ifstream in("test.txt");
	//std::cin.rdbuf(in.rdbuf());

	int n;
	std::cin >> n;

	std::valarray<double> x(n);
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}

	std::valarray<double> y(n);
	for (int i = 0; i < n; i++) {
		std::cin >> y[i];
	}

	std::valarray<double> z(n);
	z = abs(x - y);
	double p1 = z.sum();

	std::valarray<double> temp = z*z;
	double p2 = sqrt(temp.sum());

	temp *= z;
	double p3 = pow(temp.sum(), 1.0 / 3.0);

	double pm = z.max();

	std::cout << std::fixed << std::setprecision(10) << p1 << std::endl;
	std::cout << std::fixed << std::setprecision(10) << p2 << std::endl;
	std::cout << std::fixed << std::setprecision(10) << p3 << std::endl;
	std::cout << std::fixed << std::setprecision(10) << pm << std::endl;

}