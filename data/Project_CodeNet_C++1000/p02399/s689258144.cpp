#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	double d;
	int m, n, f, mold;
	cin >> m >> n;
	d = m / static_cast<double>(n);
	mold = m % n;
	f = m / n;
	cout << f << " " << mold << " ";
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(5);
	cout << d << endl;
	return 0;
}
