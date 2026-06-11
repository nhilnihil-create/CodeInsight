#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k,mod=1e9+7,ans=0;
int a[100005];

int quick_power(int a,int b)
{
	int res=1;
	for (;b;b=b>>1,a=(a*a)%mod)
	{
		if (b&1)  res=(res*a)%mod;
	}
	return res;
}

signed main()
{
	cin>>n>>k;
	for (int i=k;i>=1;i--)
	{
		a[i]=quick_power(k/i,n)%mod;
		for (int j=2*i;j<=k;j+=i)  a[i]=((a[i]-a[j])%mod+mod)%mod;
	}
	for (int i=1;i<=k;i++)  ans=(ans+a[i]*i)%mod;
	cout<<ans<<endl;
	
	return 0;
}
