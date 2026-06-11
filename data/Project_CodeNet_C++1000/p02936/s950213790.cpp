#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int sum[200005];
void dfs(int u, int p){
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == p) continue;
        sum[v] += sum[u];
        dfs(v, u);
    }
}
int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i=1;i<=n-1;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for(int i=1;i<=q;i++){
        int p, x;
        scanf("%d%d", &p, &x);
        sum[p] += x;
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++) printf("%d ", sum[i]);
}