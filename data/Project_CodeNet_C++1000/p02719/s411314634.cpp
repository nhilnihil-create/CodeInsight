#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	ll n,k;
	cin>>n>>k;
	if(k>=n)
		cout<<min(k-n,(k-(k-n)))<<endl;
	else
	{
		ll l = (n-k)/k;
		l = n - l*k;
		ll mini = l;
		map<ll,ll> m;
		while(m[l]==0)
		{
			m[l] = 1;
			l = abs(l-k);
			mini = min(mini,l);
		}
		cout<<mini<<endl;
	}
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