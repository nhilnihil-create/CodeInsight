#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll x,n,ans,minDif=LLONG_MAX;
	cin>>x>>n;
	map<ll,bool>m;
	for (int i=0;i<n;i++)
	{
		ll tmp;
		cin>>tmp;
		m[tmp]=1;
	}
	for (int i=0;i<=101;i++)
	{
		if (!m[i])
		{
			ll tmpDif=abs(x-i);
			if (tmpDif<minDif)
			{
				ans=i;
				minDif=tmpDif;
			}
		}
	}
	cout<<ans<<"\n";
}