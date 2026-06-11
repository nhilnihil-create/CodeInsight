#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],b[maxn],dp[maxn][maxn],n,m;
const ll mod=1000000007;

int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read(),dp[i][0]=1;
	for(int i=1;i<=m;i++) b[i]=read(),dp[0][i]=1; dp[0][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		if(a[i]==b[j]) dp[i][j]+=dp[i-1][j-1]; dp[i][j]=(dp[i][j]+mod)%mod;
	}
	cout<<dp[n][m]<<endl;
	return 0;
}