
// Problem : C - : (Colon)
// Contest : AtCoder - AtCoder Beginner Contest 168
// URL : https://atcoder.jp/contests/abc168/tasks/abc168_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
	ios::sync_with_stdio(0);
	cin.tie(0);
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
	//apply rule of cosines
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