#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,q,ans=0,a,b,c;
	cin>>n;
	map<ll,ll>m;
	while (n--)
	{
		cin>>a;
		ans+=a;
		m[a]++;
	}
	cin>>q;
	while (q--)
	{
		cin>>b>>c;
		ans+=m[b]*(c-b);
		m[c]+=m[b];
		m[b]=0;
		cout<<ans<<"\n";
	}
}