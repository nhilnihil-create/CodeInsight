#include <iostream>
#include <cmath>

using namespace std;

const double pi = 4*atan(1);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(5);
	double r;
	cin>>r;
	cout<<r*r*pi<<' '<<2*r*pi<<'\n';
	return 0;
}

