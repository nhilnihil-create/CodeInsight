#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int x, y;
	cin>>x>>y;
	cout << x / y << ' ' << x % y << ' ';
	double d_x = x;
	double d_y = y;
	cout << fixed << setprecision(6) << d_x / d_y << endl;
	return 0;

}
