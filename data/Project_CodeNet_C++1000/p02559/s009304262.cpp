#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
/* constexpr ll MOD = ll(1e9) + 7LL; */
/* constexpr ll MOD = 998244353LL; */
ll MOD = 200003LL;

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (v.size() == 0) return os;
    for (int i = 0; i < (int)v.size() - 1; ++i) {
        os << v[i] << " ";
    }
    os << v[v.size() - 1];
    return os;
}

void solve() {
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);
    REP(i, n) {
        int a;
        cin >> a;
        fw.add(i, a);
    }
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }
}

int main() {
    solve();
    char tmp;
    while (cin >> tmp) {
        cin.putback(tmp);
        solve();
    }
}
