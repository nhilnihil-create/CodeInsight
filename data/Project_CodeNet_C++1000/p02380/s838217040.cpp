#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

static const double pi = 3.141592653589793;
int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	double ret3 = b * sin(c * pi / 180);
	double ret1 = a * ret3 / 2;
	double ret2 = sqrt(pow(ret3, 2) + pow(a - b * cos(c * pi / 180), 2));
	cout << setprecision(10) << ret1 << " " << ret2 + a + b << " " << ret3 << endl;
	return 0;
}

