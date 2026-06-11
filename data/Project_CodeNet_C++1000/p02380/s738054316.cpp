#include "iostream"
#include "math.h"


int main()
{
	double a, b, C, S, L, h, rad;
	std::cin >> a >> b >> C;
	rad = C / 180.0 * 3.14159265358979;
	S = ((a * b) * sin(rad)) / 2;
	L = a + b + sqrt((a*a) + (b*b) - (2 * a * b * cos(rad)));
	h = b * sin(rad);
	std::cout << std::fixed << S << std::endl << std::fixed << L << std::endl << std::fixed << h << std::endl;
    return 0;
}