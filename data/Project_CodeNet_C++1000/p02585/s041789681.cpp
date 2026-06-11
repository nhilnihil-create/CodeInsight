#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll N, K;
    cin >> N >> K;

    vec<ll> P(N);
    rep(i, N) cin >> P[i], --P[i];

    vec<ll> C(N);
    rep(i, N) cin >> C[i];

    ll ans = -1e18 - 9;
    rep(i, N) {
        ll now = i;
        ll smS = 0;
        vec<ll> t;
        while (1) {
            smS += C[now];
            t.push_back(smS);
            now = P[now];
            if (now == i) break;
        }
        int L = t.size();
        rep(j, L) {
            ll zan = K - (j + 1);
            if (zan < 0) break;
            ll tmp = t[j];
            ll e   = zan / L;
            ans    = max({ans, tmp, tmp + smS * e});
        }
    }
    cout << ans << '\n';
}
