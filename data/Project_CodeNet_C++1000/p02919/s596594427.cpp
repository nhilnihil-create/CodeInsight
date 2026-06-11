#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n); i >= 0; i--)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 2100100100;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> P(N + 1);
    vector<pair<ll, ll>> V;
    REP(i, N) {
        cin >> P.at(i + 1);
        V.push_back(make_pair(P[i + 1], i + 1));
    }
    sort(ALL(V), greater<pair<ll, ll>>());

    multiset<ll> s;
    s.insert(0);
    s.insert(0);
    s.insert(N + 1);
    s.insert(N + 1);
    ll ans = 0;
    for (auto v : V) {  // x < y < v.second < z < w
        auto it = s.lower_bound(v.second);
        ll z = *it;
        it++;
        ll w = *it;
        it--;
        it--;
        ll y = *it;
        it--;
        ll x = *it;
        ans += ((w - z) * (v.second - y) + (z - v.second) * (y - x)) * v.first;
        // prllf("x:%d, y:%d, id:%d, z:%d, w:%d ,plus:%d\n", x, y, v.second, z, w,(w - z) * (v.second - y) + (z -
        // v.second) * (y - x));
        s.insert(v.second);
    }

    cout << ans << endl;
    return 0;
}
