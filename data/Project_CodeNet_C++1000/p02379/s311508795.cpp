#include<iostream>
#include<iomanip>
#include<cmath>
int main()
{
	double x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	std::cout << std::fixed << std::setprecision(8) << hypot(x1 - x2, y1 - y2) << std::endl;
	return 0;
}
