#include<iostream>
#include<cstdlib>
const double pi =3.141592653589793238;
using namespace std;
int main()
{
	double area, r, circumference;
	cin >> r;
	area = pi * r*r;
	circumference = 2 * pi*r;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(6);
	cout << area << " " << circumference << endl;
	return 0;
}
