#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double r;
	cin >> r;
	cout << setprecision(20) << r * r * M_PI << " " << 2 * M_PI * r << endl;
}
