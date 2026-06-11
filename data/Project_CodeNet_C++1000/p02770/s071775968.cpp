#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // 減少した回数と変わらなかった回数を求める
    int K, Q;
    cin >> K >> Q;
    vector<int> D(K);
    rep(i, K) cin >> D[i];
    rep(i, Q) {
        int n, x, m;
        cin >> n >> x >> m;
        // 長さnの数列、初項はx、mod m
        int ans = n - 1;
        int time = (n-1) / K;
        int remain = (n-1) % K;
        vector<int> Dcur = D;
        rep(i, K) Dcur[i] %= m;
        ll total = accumulate(Dcur.begin(), Dcur.end(), 0ll);
        total *= time;
        rep(j, remain) total += Dcur[j];
        total += x;
        ll sub = 0;
        rep(j, K) if (Dcur[j] == 0) sub++;
        sub *= time;
        rep(j, remain) if (Dcur[j] == 0) sub++;
        ans -= sub + (total / m - x / m);
        cout << ans << '\n';
    }
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}