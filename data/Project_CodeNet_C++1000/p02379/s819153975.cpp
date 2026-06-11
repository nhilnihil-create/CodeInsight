#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double x1, y1, x2, y2;
	double d;
	cin >> x1 >> y1 >> x2 >> y2;
	d = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
	cout << fixed << setprecision(4) << d << endl;
}
