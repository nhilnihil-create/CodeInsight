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

    ll ans = -1e18;
    rep(i, N) {
        vec<ll> cycle;

        ll now = i;
        ll sm  = 0;

        while (true) {
            sm += C[now];
            cycle.push_back(sm);
            now = P[now];
            if (now == i) break;
        }

        ll tmp = -1e18;
        ll sz  = cycle.size();
        rep(j, sz) {
            if(K<j+1) break;
            ll roop = (K - j - 1) / sz;
            if (sm > 0) {
                tmp = sm * roop + cycle[j];
            } else {
                tmp = cycle[j];
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}
