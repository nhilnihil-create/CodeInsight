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
        vec<ll> sm;
        while (1) {
            smS += C[now];
            sm.push_back(smS);
            now = P[now];
            if (now == i) break;
        }
        rep(j, sm.size()) {
            ll tmp     = -1e18 - 9;
            ll zan     = K - (j + 1);
            if(zan < 0) break;
            ll roopCnt = zan / sm.size();
            ll roopSm  = smS * roopCnt;
            tmp        = max({tmp, sm[j], sm[j] + roopSm});
            ans        = max(ans, tmp);
        }
    }
    cout << ans << '\n';
}
