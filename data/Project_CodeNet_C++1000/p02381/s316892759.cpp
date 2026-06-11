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

	while (n != 0) {

		std::valarray<double> s(n);
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}

		double ave = s.sum() / n;
		s -= ave;
		s *= s;
		double dev = sqrt(s.sum() / n);

		std::cout << std::fixed << std::setprecision(10) << dev << std::endl;

		std::cin >> n;
	}
	
}