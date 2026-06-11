#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll N, M;
vector<P> v;
int main() {
    cin >> N >> M;
    v.resize(M);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        int s = 0;
        rep(j, b) {
            ll c; cin >> c;
            c--;

            s += (1LL << c);
        }

        v[i] = P(s, a);
    }

    vector<ll> dp(1LL << N, INF);
    dp[0] = 0;

    // ある集合から移動
    for (int i = 0; i < 1LL << N; i++) {
        for (int j = 0; j < M; j++) {
            ll target = v[j].first;
            ll cost = v[j].second;
            dp[i | target] = min(dp[i | target], dp[i] + cost);
        }
    }

    ll ans = dp.back();
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}