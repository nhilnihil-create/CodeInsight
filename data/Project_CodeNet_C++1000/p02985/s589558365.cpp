#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,k,dp[maxn],ind[maxn],f,vis[maxn],d[maxn];
vector <int> mp[maxn];
const ll mod=1000000007;
queue <int> q;

int main()
{
	n=read(); k=read(); ll ans=1,f=0;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		mp[u].pb(v); mp[v].pb(u); ind[u]++; ind[v]++;
	}
	rep(i,1,n) if(ind[i]==1) {f=i; break;}
	q.push(f); vis[f]=1; ans=k;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i];
			if(vis[v]) continue;
			q.push(v); vis[v]=1; d[u]++; d[v]++;
			ans=(ans*(k-d[u]))%mod;
		}
		//cout<<u<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}