#include<iostream>
#include<cmath>
#include<iomanip>

int main(void) {
	double x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	auto calc_dist = [&]() {
		return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	};
	std::cout << std::fixed << std::setprecision(15) << calc_dist() << '\n';
	return 0;
}

