#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
const int mod=1e9+7;
int f[2][64];
int modp(int a,int b)
{
	if(b==0)return 1;
	int u=modp(a,b/2);
	u=(u*u)%mod;
	if(b&1)return (a*u)%mod;
	return u;
}
int32_t main()
{
	int n=in();int x;
	
	for(int i=0;i<n;i++)
	{
		x=in();
		for(int j=0;j<64;j++)
		{
			f[(x>>j)&1][j]++;
		}
	}
	int ans=0;
	for(int i=0;i<64;i++)
	{
		x=(f[0][i]*f[1][i])%mod;
		x*=modp(2,i);
		x%=mod;
		ans+=x;ans%=mod;		
	}
	cout<<ans;
	
	
	
}