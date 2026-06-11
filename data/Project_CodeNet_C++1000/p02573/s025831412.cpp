#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
vector<int> adj[MAXN];
bool visited[MAXN];
int n,m,mx=0,curr=0;

void dfs(int node){
    visited[node] = true;
    for(int next : adj[node]){
        if(!visited[next]){
            curr++;
            dfs(next);
        }
    }
}

int main(){
    cin >> n >> m;
    int a,b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            curr = 1;
            dfs(i);
            mx = max(mx,curr);
        }
    }
    cout << mx << endl;
}
