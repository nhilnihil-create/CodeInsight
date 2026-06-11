/* When Talent doesn't work, Hard work beats Talent*/

#include"bits/stdc++.h"

using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define sp " "
#define int long long
#define scanstr(s) cin>>ws; getline(cin,s);

const double PI=3.141592653589793;

void solve()
{
	long double a,b,h,m;
	cin>>a>>b>>h>>m;
	long double ang=m*6;
	long double s=(h+m/60.0)*30;
	ang=abs(s-ang);
	ang=ang*PI/180;
	long double len= a*a + b*b - 2*a*b*cos(ang);
	len=sqrt(len);
	cout<<fixed<<setprecision(20)<<len<<nl;
	return ;
}

int32_t main()
{
	FastIO;
	solve();
	return 0;
}
