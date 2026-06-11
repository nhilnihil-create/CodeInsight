#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define F0R(i, a) for (int i = 0; i < (a); i++)
const int mod = 1e9 + 7;
const char nl = '\n';

vector<int> adj[200001];
bool vis[200001];
int cnt = 0;
 
void dfs(int u, int sum = 1){
    cnt++;
    vis[u] = 1;
     bool ok = 0;
     for(auto v : adj[u]){
         if(!vis[v]){
             dfs(v, sum + 1);
         }
     }
    return;
}
 
int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    F0R(i, m){
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int mx = 0;
    F0R(i, n){
        if(!vis[i]){
            cnt = 0;
            dfs(i);
            mx = max(mx, cnt);
        }
    }
    cout << mx << nl;
    return 0;
}