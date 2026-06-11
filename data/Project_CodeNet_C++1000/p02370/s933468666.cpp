#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=10005;

int n,m;
bool vis[maxn];
vector<int>G[maxn];
vector<int>ans;

void dfs(int u) {
    vis[u]=1;
    for (int v:G[u])
        if (!vis[v]) dfs(v);
    ans.pb(u);
}

int main() {
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v);
    }
    for (int i=0;i<n;i++)
        if (!vis[i]) dfs(i);
    for(auto it=ans.rbegin(); it!=ans.rend();it++) cout <<*it << endl;
}
