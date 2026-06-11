#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll N = 1e2 + 5;

ll n, m;
ll dx[] = {1, 0};
ll dy[] = {0, 1};
ll dp[N][N];
char grid[N][N];

bool outside(ll r, ll c) {
    return r < 0 || r > n || c < 0 || c > m;
}

ll f(ll r, ll c) {
    if(r == n && c == m) return grid[r][c] == '#';
    if(dp[r][c] != -1) return dp[r][c];
    ll res = INT_MAX;
    for(ll i = 0; i < 2; i++) {
        ll nr = r + dx[i], nc = c + dy[i];
        if(outside(nr, nc)) continue;
        if(grid[r][c] == '.') res = min(res, f(nr, nc));
        else if(grid[r][c] == '#' && grid[nr][nc] == '#') res = min(res, f(nr, nc));
        else if(grid[r][c] == '#' && grid[nr][nc] == '.') res = min(res, f(nr, nc) + 1);
    }
    return dp[r][c] = res;
}

void solve() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(1, 1) << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}