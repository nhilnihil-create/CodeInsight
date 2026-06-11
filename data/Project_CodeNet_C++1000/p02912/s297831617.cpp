#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,s,e) for(ll i=s;i<=e;i++)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll a[n];
	rep(i,0,n-1)
	cin>>a[i];
	priority_queue <ll> q;
	rep(i,0,n-1)
	q.push(a[i]);
	ll x;
	while(m--)
	{	
		x=q.top();
		x/=2;
		q.pop();
		q.push(x);
	}
	ll ans=0;
	while(n--)
	{
		ans+=q.top();
		q.pop();

	}
	cout<<ans;
	return 0;
	
}