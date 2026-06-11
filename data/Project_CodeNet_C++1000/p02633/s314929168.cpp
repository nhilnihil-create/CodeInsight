#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) \
    for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
    for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = ll(1e9) + 7LL;

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (v.size() == 0) return os;
    for (int i = 0; i < v.size() - 1; ++i) {
        os << v[i] << " ";
    }
    os << v[v.size() - 1];
    return os;
}

struct edge {int to, cap, rev;};

int dfs(int v, int t, int f, vector<bool>& used, vector<vector<edge>>& G) {
    if (v == t) return f;
    used[v] = true;
    REP(i, G[v].size()) {
        edge& e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap), used, G);
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

void solve() {
    int x;
    cin >> x;
    if (360 % x == 0) {
        cout << 360 / x << endl;
        return;
    }
    ll ans = x;
    while (ans % 360 != 0) {
        ans += x;
    }
    cout << ans / x << endl;
}

int main() {
    char tmp;
    while (cin >> tmp) {
        cin.putback(tmp);
        solve();
    }
}
