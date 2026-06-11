// 2014/08/01 Tazoe

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, C;
	cin >> a >> b >> C;

	double S = (double)a*(double)b*sin(M_PI*(double)C/180.0)/2.0;
	double c = sqrt((double)a*(double)a+(double)b*(double)b-2.0*(double)a*(double)b*cos(M_PI*(double)C/180.0));
	double L = (double)a+(double)b+c;
	double h = (double)b*sin(M_PI*(double)C/180.0);

	cout.precision(8);
	cout << fixed << S << endl;
	cout << fixed << L << endl;
	cout << fixed << h << endl;

	return 0;
}