#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

vector<vector<int>> adj;
vector<int> vis;


void dfs(int n)
{
	vis[n]=1;
	for(auto i :adj[n])
	{
		if(vis[i]!=1)
			dfs(i);
	}
}

 
int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
   adj.resize(n+1,vector<int>());
   vis.resize(n+1,0);
   int a,b;
   for(int i=0;i<m;i++)
   {
   		cin>>a>>b;
   		adj[a].push_back(b);
   		adj[b].push_back(a);
   }
   int ans=0;
   for(int i=1;i<=n;i++)
   {
   		if(vis[i]!=1)
   		{
   			ans++;
   			dfs(i);
   		}
   }
   cout<<ans-1<<endl;
	return 0;

}