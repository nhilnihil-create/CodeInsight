#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,mod=1e9+7;

inline int ksm(int a,int b)
{
	int ans=1;
	a=a%mod;
	while(b)
	{
	  if(b&1) ans=(ans*a)%mod;
	  a=(a*a)%mod,b>>=1;
	}
	return ans;
}

signed main()
{
	cin>>n;
	cout<<(ksm(10,n)-(2*ksm(9,n))%mod+ksm(8,n)+mod)%mod;
	return 0;
}