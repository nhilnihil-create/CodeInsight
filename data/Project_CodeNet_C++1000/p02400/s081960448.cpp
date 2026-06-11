#include <iostream>
#include <cstdio>

const double PHI = 3.141592653589;

int main()
{
	double r;
	std::cin >> r;
	printf("%.5f %.5f", r*r*PHI, 2 * r*PHI);
	return 0;
}