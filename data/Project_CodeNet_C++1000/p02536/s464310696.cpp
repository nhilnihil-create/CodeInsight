#include<bits/stdc++.h>
using namespace std;

void dfs(int s, vector<vector<int>> &l, vector<int> &visited)
{
	visited[s]=1;
	for(int i=0; i<l[s].size(); i++)
	{
		int v=l[s][i];
		if(visited[v]==0)
			dfs(v,l,visited);
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> l(n);
	for(int i=0; i<m; i++)
	{
		int u,v;
		cin>>u>>v;
		l[u-1].push_back(v-1);
		l[v-1].push_back(u-1);
	}

	vector<int> visited(n,0);
	int ans=0;
	for(int i=0; i<n; i++)
	{
		if(visited[i]==0){
			ans++;
			dfs(i,l,visited);
		}
	}
	cout<<ans-1<<endl;
	return 0;	
}
