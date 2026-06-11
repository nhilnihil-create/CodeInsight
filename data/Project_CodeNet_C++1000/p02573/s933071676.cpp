#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e6+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=200001;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
vector<int>v[maxn];
int l;
int vis[maxn];
void dfs(int node)
{
	vis[node]=1;
	l++;
	for(int child: v[node])
	{
		if(!vis[child])
			dfs(child);
	}
}
int main()
{
	fastio;
	int t;
	int i,j,k,n,m;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>j>>k;
		v[j].pb(k);
		v[k].pb(j);
	}
	k=0;
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			l=0;
			dfs(i);
			k=max(k,l);
		}
	}
	cout<<k;
	

}