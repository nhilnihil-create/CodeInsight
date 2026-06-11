#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	if(n<=a&&a!=0)
	{
		cout<<n;
	}
	else
	{
		ll g=n/(a+b);
		ll r=n%(a+b);
		ll ans=(g*a)+min(a,r);
		cout<<ans;
	}
}