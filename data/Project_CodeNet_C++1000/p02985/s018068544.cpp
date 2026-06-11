#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n , k , tmp , ans;
vector<int> g[N];
void dfs(int node , int par) {
    if(par == -1)
        tmp = k - 1;
    else
        tmp = k - 2;
    for(auto &i : g[node])
        if(i != par)
            ans = (1ll * ans * tmp--) % mod;
    for(auto &i : g[node])
        if(i != par)
            dfs(i , node);
}
int main() {
    abdelrahman010
    cin >> n >> k;
    for(int i = 1;i < n;i++) {
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = k;
    dfs(1 , -1);
    cout << ans;
    return 0;
}