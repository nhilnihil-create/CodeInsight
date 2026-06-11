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
    int N;
    cin >> N;

    vector<int> A(N);
    unordered_map<int, int> m;
    m.reserve(N);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll t;
        cin >> t;
        int x = i + 1 - t;

        if (m.find(x) != m.end()) {
            ans += m[x];
        }

        if (m.find(i + 1 + t) == m.end()) {
            m.emplace(i + 1 + t, 1);
        } else {
            ++m[i + 1 + t];
        }
    }
    cout << ans << endl;
}