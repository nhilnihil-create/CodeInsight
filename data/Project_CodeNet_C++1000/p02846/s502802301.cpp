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
constexpr ll MOD = 1e9 + 7LL;
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
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if (t1*a1 + t2*a2 < t1*b1 + t2*b2) {
        swap(a1,b1);
        swap(a2,b2);
    } else if (t1*a1 + t2*a2 == t1*b1 + t2*b2) {
        cout << "infinity" << endl;
        return;
    } 
    if (t1*a1 > t1*b1) {
        cout << 0 << endl;
        return;
    } else {
        ll dist_mid = t1*b1 - t1*a1, dist_en = t1*a1 + t2*a2 - (t1*b1 + t2*b2);
        if (dist_mid % dist_en == 0) {
            cout << 2LL * (dist_mid / dist_en) << endl;
        } else {
            cout << 1LL + 2LL*(dist_mid / dist_en) << endl;
        }
        return;
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

