#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    int ans = INF;
    vector<int> cost(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i,n) {
        cin >> cost[i];
        rep(j,m) cin >> a[i][j];
    }
    rep(is,1<<n) {
        vector<int> cf(m);
        int now = 0;
        rep(i,n) {
            if (is>>i&1) {
                rep(j,m) cf[j] += a[i][j];
                now += cost[i];
            }
        }
        bool ok = true;
        rep(i,m) {
            if (cf[i] < x) ok = false;
        }
        if (ok) ans = min(ans, now);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}