#include <iostream>
#include <iomanip>
#include <math.h>

#define INPUT_FROM_FILE (0)
#if INPUT_FROM_FILE
#include <fstream>
#endif

int main(int argc, char **argv){
#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
#endif
	double x1 = 0;
	double y1 = 0;
	double x2 = 0;
	double y2 = 0;

#if INPUT_FROM_FILE
	ifs >> x1 >> y1 >> x2 >> y2;
#else
	std::cin >> x1 >> y1 >> x2 >> y2;
#endif
	std::cout << std::fixed << std::setprecision(5) << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) << std::endl; 
	return 0;
}