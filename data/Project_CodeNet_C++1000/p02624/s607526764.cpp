#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,ans=0;
	cin>>n;
	for (ll i=1;i<=n;i++)
	{
		for (ll j=i;j<=n;j+=i)
		{
			ans+=j;
		}
	}
	cout<<ans<<"\n";
}