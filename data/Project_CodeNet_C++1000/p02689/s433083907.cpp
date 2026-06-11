#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2>
inline bool chmin(T1 &a, const T2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for (ll i = 0; i < N; ++i) {
        cin >> H[i];
    }

    vector<vector<ll>> edge(N);
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }

    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        bool is_good = true;
        for (auto e : edge[i]) {
            if (H[e] >= H[i]) {
                is_good = false;
                break;
            }
        }
        if (is_good) ++ans;
    }
    cout << ans << endl;
}