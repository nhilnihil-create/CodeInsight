#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
const int mod=998244353;
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
	int n=in();int s=in();
	vector<int> a(n);for(auto &i:a)i=in();
	vector<vector<int>> dp(n+1, vector<int>(s+1));
	dp[0][0]=modp(2,n);
	int inv2=modp(2,mod-2);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=s;j++)
		{
			dp[i+1][j]+=dp[i][j];
			dp[i+1][j]%=mod;
			if(j+a[i]<=s)
			{
				dp[i+1][j+a[i]]+=dp[i][j]*inv2;
				dp[i+1][j+a[i]]%=mod;
			}
		}
		
	}
	cout<<dp[n][s];
	
}