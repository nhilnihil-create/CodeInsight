#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2e5 +7;
vector<int>g[maxn];
bool mark[maxn];
vector<int>p(maxn), x(maxn), cnt(maxn, 0);

void dfs(int v, int ancestor) {
    mark[v] = 1;
    for(int to : g[v]) {
        if(ancestor == to)  continue;
        if(!mark[to]) {
            cnt[to] += cnt[v];
            dfs(to, v);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, u, v; cin>>n>>q;
    for(int i=1; i<n; i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=q; i++) {
        cin>>p[i]>>x[i];
        cnt[p[i]] += x[i];
    }

    dfs(1, 0);
    for(int i=1; i<=n; i++) cout<<cnt[i]<<" ";
    return 0;
}