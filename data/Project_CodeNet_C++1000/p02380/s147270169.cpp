#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char const* argv[])
{
	int a, b, C;
	cin >> a >> b >> C;
	cout << setprecision(15);
	cout << 0.5 * (double)a * b * sin((double)C*M_PI/180.) << endl;
	cout << a + b + sqrt((double)a*a + (double)b*b-2*a*b*cos(C*M_PI/180.)) << endl;
	cout << (double)a * b * sin(C*M_PI/180.) / (double)a << endl;
	return 0;
}

