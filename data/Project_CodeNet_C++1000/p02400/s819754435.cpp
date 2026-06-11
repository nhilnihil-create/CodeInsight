#include <iostream>
#include <cmath>

#define PI acos(-1.0)

using namespace std;

int main()
{
	double r;
	cin >> r;

	cout << fixed;
	cout.precision(6);

	cout << r*r*PI << " " << 2*r*PI << endl;

	return 0;
}