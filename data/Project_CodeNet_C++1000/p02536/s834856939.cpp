#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int u, bool visited[], vector<int> adj[]){
  visited[u] = true;
  for(auto x: adj[u]){
    if(!visited[x])
      dfs(x, visited, adj);
  }
  return;
}

int32_t main(){
    int t;
    t = 1;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[m],b[m];
        vector<int> adj[n+1];
        for(int i=0; i<m; i++){
          cin >> a[i] >> b[i];
          adj[a[i]].push_back(b[i]);
          adj[b[i]].push_back(a[i]);
        }
        bool visited[n+1]={0};
        int count = 0;
        for(int i=1; i<=n; i++){
          if(!visited[i]){
            count++;
            dfs(i, visited, adj);
          }
        }
        cout << count-1 << endl;
    }
}

