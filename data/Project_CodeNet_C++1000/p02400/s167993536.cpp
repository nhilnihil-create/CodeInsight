#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double r,p = 3.14159265359;
	cin >> r;
	cout << fixed << setprecision(6) << r*r*p << ' ' << setprecision(6) << (r+r)*p << endl;
	return 0;
}