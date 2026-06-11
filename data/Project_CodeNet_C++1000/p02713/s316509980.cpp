#include"bits/stdc++.h"
using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl "\n"
#define sp " "
#define int long long

int32_t main()
{
	FastIO;
	int k,ans=0;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int l=1;l<=k;l++)
			{
				int x;
				x=__gcd(i,j);
				x=__gcd(x,l);
				ans+=x;
			}
		}
	}
	cout<<ans<<nl;
	return 0;
}
