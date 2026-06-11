#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double a = 0, b = 0, c = 0, ang = 0, pi = 3.141592653589793;

	cin >> a >> b >> ang;

	ang = ang * pi / 180;
	c = sqrt(a * a + b * b - 2 * a * b * cos(ang));

	cout << setprecision(13) << fixed << a * b * sin(ang) / 2 << endl
		<< a + b + c << endl
		<< b * sin(ang) << endl;

    return 0;
}