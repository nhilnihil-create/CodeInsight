#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 305
#define inf 1e18
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll dp[maxn][maxn],a[maxn],n,k;

int main()
{
	n=read(); k=read(); rep(i,1,n) a [i]=read();
	rep(i,1,n) rep(j,1,n) dp[i][j]=inf;
	rep(i,1,n) dp[i][1]=a[i];
	rep(i,2,n)
	{
		rep(j,2,i)
		{
			ll tmp=inf;
			for(int k=1;k<=i-1;k++)
			{
				ll p=dp[k][j-1]; if(p==inf) continue;
				if(a[i]>a[k]) p+=(a[i]-a[k]);
				tmp=min(tmp,p);
			}
			dp[i][j]=tmp;
		}
	}
	ll ans=inf;
	for(int i=n;i>=n-k;i--) ans=min(ans,dp[i][n-k]); cout<<ans<<endl;
	return 0;
}