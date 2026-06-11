#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100000];
bool vis[100000];

void dfs(int u){
    if(!vis[u]){
        vis[u] = true;
        for(int& v: adj[u]){
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int c = -1;
    for(int i = 0;i < n;i++){
        if(!vis[i]){
            c++;
            dfs(i);
        }
    }
    cout << c << endl;
}
