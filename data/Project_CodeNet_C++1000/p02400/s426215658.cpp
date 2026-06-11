#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double PI = 3.14159265359;
	double r = 0;
	cin >> r;

	cout << fixed << setprecision(6);
	cout << PI * r * r << " " << 2 * PI * r << endl;

	return 0;
}