#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
	double x1, y1, x2, y2;
	double dist;
	cin >> x1 >> y1 >> x2 >> y2;

	dist = sqrt(std::pow((x2 - x1), 2.0) + std::pow((y2 - y1), 2.0));

	cout << std::fixed << std::setprecision(10) << dist << endl;
	return 0;
}