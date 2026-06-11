#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(vector<vector<int>> &adj, int s, vector<bool> &visited){
    visited[s] = 1;
    
    for(int i : adj[s]){
        if(!visited[i])
            dfs(adj, i, visited);
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    
    for(int i = 0; i < m; i++){
        int p, q;
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    
    vector<bool> visited(n+1);
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            dfs(adj, i, visited);
            ans++;
        }
    }
    
    cout << ans-1 << "\n";
    
}
