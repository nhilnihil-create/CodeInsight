#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;

int n,s;
int a[3005],dp[3005];

int quick_power(int x,int y)
{
	int res=1;
	for (;y;y=y>>1,x=(x*x)%mod)
	{
		if (y&1)  res=(res*x)%mod;
	}
	return res;
}

signed main()
{
	cin>>n>>s;
	for (int i=1;i<=n;i++)  cin>>a[i];
	
	dp[0]=quick_power(2,n);
	for (int i=1;i<=n;i++)
	{
		for (int j=s;j>=a[i];j--)  dp[j]=(dp[j]+(dp[j-a[i]]*499122177)%mod)%mod;
	}
	cout<<dp[s]<<endl;
	
	return 0;
}