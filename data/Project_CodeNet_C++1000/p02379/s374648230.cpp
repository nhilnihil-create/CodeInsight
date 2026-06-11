#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
	double x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << fixed << setprecision(8);
	cout << sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)) << endl;
	return 0;
}