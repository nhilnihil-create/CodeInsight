#include<iostream>
using namespace std;

int main()
{
	const double pi = 3.141592653589;
	double r, s, l;
	cin >> r;
	l = 2 * pi*r;
	s = pi*r*r;
	cout << fixed << s << " " << l << endl;
    return 0;
}