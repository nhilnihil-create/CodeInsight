#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int)1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; __print(x);


int n, q;
vector<int> adj[210000];
i64 incr_val[210000];
int visited[210000];
i64 ans[210000];

void dfs(int u, i64 par_val)
{
    if(visited[u]) return;
    visited[u] = true;
    i64 val = par_val + incr_val[u];
    ans[u] = val;
    for(int to : adj[u]) {
        dfs(to, val);
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n-1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    while(q--) {
        int x;
        i64 y;
        scanf("%d%lld", &x, &y);
        incr_val[x] += y;
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    puts("");
}
