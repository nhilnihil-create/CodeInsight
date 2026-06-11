#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#define _PI (3.141592653589793)
int main()
{
	int A, B, H, M;
	std::cin >> A >> B >> H >> M;
	const double m = H * 60 + M;
	const double degA = (m / (12 * 60))*360;
	const double degB = (m / (1 * 60))*360;
	const double yA = A * sin(degA / 180 * _PI);
	const double xA = A * cos(degA / 180 * _PI);
	const double yB = B * sin(degB / 180 * _PI);
	const double xB = B * cos(degB / 180 * _PI);

	std::cout << std::fixed << std::setprecision(15) << sqrt(pow(xA - xB, 2) + pow(yA - yB, 2)) << std::endl;

	return 0;
}