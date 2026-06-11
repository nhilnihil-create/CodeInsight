
#include <bits/stdc++.h>
using namespace std;

double absol(double a, double b)
{
	double to_return = a - b;
	if(to_return < 0.00)
	{
		to_return = to_return * -1.00;
	}
	return to_return;
}

int main()
{
	int a,b,h,m;
	cin>>a>>b>>h>>m;
	double deg_min = 6 * m;
	double deg_hr = 30*h;
	deg_hr += 1.00 * 0.5 * m;
	double delta = absol(deg_min, deg_hr);
	if(delta > 180.00)
	{
		delta = 360.00 * 1.00 - delta;
	}
	double x = a*a*1.00;
	x += b*b*1.00;
	double z = 2.00*a*b*1.00;
	delta = delta * 3.141592653589793238;
	delta = delta/(180.00 * 1.00);
	z = z * cos(delta);
	x -= z;
	double ans = sqrt(x);
	cout<<setprecision(30)<<ans;
	return 0;
}
