#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll ans=b-a+1;
	if(a==b)
	{
		if(a%c==0||a%d==0)
			cout<<0;
			return 0;
	}
	ans=ans-(b/c - (a-1)/c) - (b/d - (a-1)/d) + (b/lcm(c,d) - (a-1)/lcm(c,d));
	cout<<ans;
	return 0;
}
