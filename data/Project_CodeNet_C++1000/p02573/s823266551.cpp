# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
# define int long long

using namespace std;

const int N = 2e5 + 7;
const int mod = 1e9 + 7;

vector < int > adj[N];
int used[N], cnt, mx;

void dfs( int v ) {
    used[v] = 1;
    cnt++;
    for ( auto u: adj[v] ) {
        if ( !used[u] ) {
            dfs( u );
        }
    }
}

int32_t main() {
    speed;
    int n, m;
    cin >> n >> m;
    for ( int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for ( int i = 1; i <= n; i++ ) {
        if ( !used[i] ) {
            cnt = 0;
            dfs( i );
            mx = max( mx, cnt );
        }
    }
    cout << mx;
}
