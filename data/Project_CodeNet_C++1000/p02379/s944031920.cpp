#include "iostream"
#include "math.h"


int main()
{
	double x1, x2, y1, y2, result;
	std::cin >> x1 >> y1 >> x2 >> y2;
	x1 *= 1.0000000;
	x2 *= 1.0000000;
	y1 *= 1.0000000;
	y2 *= 1.0000000;
	x1 = x1 - x2;
	y1 = y1 - y2;
	result = hypot(x1, y1);
	std::cout << std::fixed << result << std::endl;
    return 0;
}