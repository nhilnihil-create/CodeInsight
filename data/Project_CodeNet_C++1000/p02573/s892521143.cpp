#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define pb push_back
#define fr first
#define sc second
#define endl '\n'

const int mxn = 1e6 + 5;
const ll MOD =  1e9 + 7;
vector<int> arr[mxn];
int sub[mxn];
int n, m, k, q;
string s, t;

void dfs(int node) {
    sub[node] = 1;
    for (int next : arr[node]) {
        if (!sub[next]) {
            dfs(next);
            sub[node] += sub[next];
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!sub[i]) {
            dfs(i);
        }
    }
    int ans = sub[1];
    for (int i = 2; i <= n; i++) ans = max(ans, sub[i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
