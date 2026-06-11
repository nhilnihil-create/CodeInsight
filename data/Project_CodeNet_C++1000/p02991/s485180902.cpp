#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int dp[maxn][3],n,m,s,t,vis[maxn][3];
vector <int> mp[maxn];
struct node{int to,x;};
queue <node> q;

int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
	}
	s=read(); t=read();
	q.push({s,0}); vis[s][0]=1;
	while(!q.empty())
	{
		node u=q.front(); q.pop();
		for(int i=0;i<mp[u.to].size();i++)
		{
			int v=mp[u.to][i];
			if(vis[v][(u.x+1)%3]) continue;
			dp[v][(u.x+1)%3]=dp[u.to][u.x]+1;
			vis[v][(u.x+1)%3]=1; q.push({v,(u.x+1)%3});
		}
	}
	if(dp[t][0]) cout<<dp[t][0]/3; else puts("-1");
	return 0;
}