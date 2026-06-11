#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int visited[100000];
void dfs(int a){
    visited[a] = 1;
    for (int u : adj[a]) {
        if (!visited[u])
            dfs(u);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans-1;
}