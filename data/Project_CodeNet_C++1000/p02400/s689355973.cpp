#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	double r;
	cin >> r;
	cout << fixed;
	cout << setprecision(8);
	cout << (M_PI * r * r) << " " << (2 * M_PI * r) <<endl;

	return 0;
}
