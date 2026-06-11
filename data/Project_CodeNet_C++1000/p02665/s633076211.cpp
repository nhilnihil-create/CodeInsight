#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<lint, lint>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vec a(n+1);
    rep(i, n+1) cin >> a[i];

    lint res = 0;

    vector<P> lr(n+1);
    lr[n] = {a[n], a[n]};

    for (int i = n-1; i >= 0; --i) {
        auto prev = lr[i+1];
        lint r = prev.second + a[i];
        lint l = (prev.first + 1) / 2 + a[i];
        lr[i] = {l, r};
    }

    if (lr[0].first > 1 || lr[0].second < 1) {
        cout << "-1" << endl;
        exit(0);
    }

    lint nodes = 1;

    for (int i = 0; i <= n; ++i) {
        lint mx = lr[i].second;
        res += min(mx, nodes);
        if (nodes > 100000000000000) continue;
        nodes -= a[i];
        nodes *= 2;
    }

    cout << res << endl;
    return 0;
}