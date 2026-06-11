#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

const ll MN = -1e18 - 99999999;

int main() {
    ll N, K;
    cin >> N >> K;

    vec<ll> P(N);
    rep(i, N) cin >> P[i], --P[i];

    vec<ll> C(N);
    rep(i, N) cin >> C[i];

    ll ans = MN;
    rep(i, N) {
        ll now = i;
        vector<int> loop;
        ll nowS = 0;

        while (1) {
            now = P[now];
            nowS += C[now];
            loop.emplace_back(C[now]);
            if (now == i) break;
        }

        ll tmp = 0;
        ll sz  = loop.size();
        rep(j, sz) {
            tmp += loop[j];
            if (j == K) break;
            if (nowS > 0) {
                ll cnt = (K - (j + 1)) / sz;
                ans = max(ans, nowS * cnt + tmp);
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << '\n';
}
