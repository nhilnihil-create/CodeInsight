#include <bits/stdc++.h>
/* #include <atcoder/all> */
#include <iostream>
using namespace std;
/* using namespace atcoder; */
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
constexpr ll MOD = 998244353;
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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<vint> v(10);
    REP(i, n) {
        int now = s[i] - '0';
        v[now].push_back(i);
    }
    int ans = 0;
    REP(i, 10) {
        if (v[i].size() == 0) continue;
        REP(j, 10) {
            if (v[j].size() == 0) continue;
            REP(k, 10) {
                if (v[k].size() == 0) continue;
                int idx_i = v[i][0];
                auto ite_j = upper_bound(ALL(v[j]), idx_i);
                if (ite_j == v[j].end()) continue;
                int idx_j = *ite_j;
                auto ite_k = upper_bound(ALL(v[k]), idx_j);
                if (ite_k == v[k].end()) continue;
                ++ans;
            }
        }
    }
    cout << ans << endl;
}


int main() {
    solve();
    char tmp;
    while (cin >> tmp) {
        cin.putback(tmp);
        solve();
    }
}

