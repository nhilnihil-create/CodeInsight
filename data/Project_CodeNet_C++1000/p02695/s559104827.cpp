#include <bits/stdc++.h>
using namespace std;


vector<int> a(12);
vector<vector<long long>> Q(51, vector<long long>(4));
int n, m, q;
long long ans = 0;
void dfs (int v, int start) {
    if (v > n) {
        long long total = 0;
        for (int i = 0; i < q; i++) {
            int fi = Q[i][0];
            int si = Q[i][1];
            if (a[si] - a[fi] == Q[i][2]) {
                total += Q[i][3];
            }
        }
        ans = max (ans, total);
        return;
    }
    for (int i = start; i <= m; i++) {
        a[v] = i;
        dfs (v + 1, i);
    }
}
void solve () {
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 4; j++) {
            long long x; cin >> x;
            Q[i][j] = x;
        }
    }
    dfs(1,1);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
