#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define ff first
#define ss second
#define prec(y,x) fixed<<setprecision(y)<<x
#define inf 1e18
#define pi 3.1415926535

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin>>s;
	if(s[0]=='S')
	{
		if(s[1]=='U')
			cout<<7;
		else
			cout<<1;
	}
	else if(s[0]=='F')
	{
		cout<<2;
	}
	else if(s[0]=='T')
	{
		if(s[1]=='H')
			cout<<3;
		else
			cout<<5;
	}
	else if(s[0]=='W')
	{
		cout<<4;
	}
	else
	{
		cout<<6;
	}
	return 0;
}

