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
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = 998244353LL;

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        os << v[i] << " ";
    }
    if (v.size() > 0) {
        os << v[v.size() - 1] << endl;
    }
    return os;
}

int main() {
    int n,s;
    cin >> n >> s;
    vint a(n);
    cin >> a;
    vector<vll> dp(n+1, vll(s + 1, 0));
    dp[0][0] = 1;
    REP(i,n){
        REP(j, s + 1){
            dp[i+1][j] = (dp[i+1][j] + 2*dp[i][j] % MOD) % MOD;
            if (j - a[i] >= 0) {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - a[i]]) % MOD;
            }
        }
    }
    cout << dp[n][s] << endl;
}
