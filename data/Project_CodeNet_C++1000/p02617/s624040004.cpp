#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	ll n;
	cin>>n;
	ll ans = 0;
	for (ll i = 1; i <= n ; ++i)
	{
		ans += (i)*(n-i+1);
	}
	for (int i = 0; i < n-1; ++i)
	{
		ll u,v;
		scanf("%lld %lld", &u, &v);
		if(u>v)
			swap(u,v);
		ans -= u*(n-v+1);
	}
	printf("%lld\n", ans);
}

int main()
{
	ll t = 1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
}