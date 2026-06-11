#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char const* argv[])
{
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << setprecision(15) << sqrt((a-c)*(a-c) + (b-d)*(b-d)) << endl;
	return 0;
}

