#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1000 * 1000 * 1000 + 7;
ll mul(ll a, ll b)
{
	return ((a%mod)*(b%mod))%mod;
}
ll add(ll a, ll b)
{
	return ((a%mod)+(b%mod))%mod;
}
ll sub(ll a, ll b)
{
	return ((a%mod)-(b%mod)+mod)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,a,b;
	cin>>n>>a>>b;
	if((b-a)%2==0)
	{
		cout<<(b-a)/2;
	}	
	else
	{
		ll u1=a;
		ll x=b;
		b-=a;
		u1+=(b-1)/2;
		b=x;
		ll u2=n-b+1;
		a+=(n-b+1);
		u2+=abs(n-a)/2;
		cout<<min(u1,u2);
	}
}
