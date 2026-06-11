#include <bits/stdc++.h>
using namespace std;


void dfs(int source, vector<int> adj[], vector<bool> &visited)
{
    visited[source] = true;
    
    for(auto v : adj[source])
    {
        if(!visited[v])
        {
            dfs(v,adj,visited);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	
	int n = 0,m = 0;
	cin>>n>>m;
	
	vector<int> adj[n+1];
	
	while(m--)
	{
	    int a = 0, b = 0;
	    cin>>a>>b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	
	
	vector<bool> visited(n+1, false);
	int components = 0;
	
	for(int i=1;i<=n;i++)
	{
	    if(!visited[i])
	    {
	        components++;
	        dfs(i, adj, visited);
	    }
	}
	
	cout<<components-1<<"\n";
	  
	return 0;
}
