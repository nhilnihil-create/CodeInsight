#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m,k,ans=0;
	cin>>n>>m>>k;
	vector<ll> a(n), b(m), aSum(n+1), bSum(m+1);
	for (ll i=0;i<n;i++)
	{
		cin>>a[i];
		aSum[i+1]=aSum[i]+a[i];
	}
	for (ll i=0;i<m;i++)
	{
		cin>>b[i];
		bSum[i+1]=bSum[i]+b[i];
	}
	//for (int i=0;i<=n;i++)cout<<aSum[i]<<" ";cout<<"\n";
	//for (int i=0;i<=m;i++)cout<<bSum[i]<<" ";cout<<"\n";
	for (ll i=0;i<=n;i++)
	{
		ll dif=k-aSum[i];
		if (dif<0)continue;
		if (dif==0)
		{
			ans = max(ans,i);
			continue;
		}
		ll j = upper_bound(bSum.begin(),bSum.end(),dif)-bSum.begin()-1;
		ans = max(ans,i+j);
	}
	cout<<ans<<"\n";
}