#include <iostream>
#include <string>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h>

#define INPUT_FROM_FILE (0)
#if INPUT_FROM_FILE
#include <fstream>
#endif

int main(int argc, char **argv){
#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
#endif
	int a = 0;
	int b = 0;
	int C = 0;
	double h = 0;
	double r = 0;
	double theta = 0;

#if INPUT_FROM_FILE
	ifs >> a >> b >> C;
#else
	std::cin >> a >> b >> C;
#endif

	r = C * M_PI / 180.0;
	h = b * sin(r);

	theta = atan2(a - b * cos(r), h);

	std::cout << std::fixed << std::setprecision(5) << 0.5 * a * h << std::endl; 
	std::cout << std::fixed << std::setprecision(5) << a + b + h / cos(theta) << std::endl; 
	std::cout << std::fixed << std::setprecision(5) << h << std::endl; 
	
	return 0;
}