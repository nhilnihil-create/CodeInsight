// 2014/07/16 Tazoe

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double r;
	cin >> r;

	double S = M_PI*r*r;
	double L = 2.0*M_PI*r;

	cout.precision(6);
	cout << fixed << S << ' ' << fixed << L << endl;

	return 0;
}