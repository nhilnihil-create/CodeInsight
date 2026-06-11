#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#define int long long int
#define inf 10000000000000000
#define mod 1000000007
void dfs(int src,vector<int> adj[],int p,int value,int dp[],int answer[])
{
	value+=dp[src];
	answer[src]=value;
	for(int x:adj[src])
	{
		if(x!=p)
		{
			dfs(x,adj,src,value,dp,answer);
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	int j;
	vector<int> adj[n+1];
	for(j=0;j<n-1;j++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int dp[n+1]={0};
	for(j=0;j<q;j++)
	{
		int x;
		cin>>x;
		int p;
		cin>>p;
		dp[x]+=p;
	}
	int answer[n+1]={0};
	dfs(1,adj,-1,0,dp,answer);
	for(j=1;j<=n;j++)
	   cout<<answer[j]<<" ";
	cout<<endl;
}
