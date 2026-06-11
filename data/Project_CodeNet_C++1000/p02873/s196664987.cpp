#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, m, n) for (ll(i) = (ll)(m); i < (ll)(n); ++i)
#define rep2(i, m, n) for (ll(i) = (ll)(n)-1; i >= (ll)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef vector<vector<vector<ll>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
template <class T> inline void print(T x) { cout << x << '\n'; }
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}
bool is_prime(ll x) {
    if (x <= 1) return false;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
// ~~~~~~~~~~~~~~memo~~~~~~~~~~~~~~
// for (int i = 0; i < n; ++i)
// v ector<long long> v(n), c(n);
// cout << res << endl;
// cout << res << '\n';
// int型の2次元配列(h×w要素の)の宣言
// vector<vector<int>> data(h, vector<int>(w));
// rotate(s.begin(), s.begin() + 1, s.end());
// sort(all(a),greater<int>());
// s.substr(0,2) 先頭から2文字切り出す
// for (auto it = mp.rbegin();it != mp.rend(); ++it)
// vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(w + 1, vector<int>(k+1, 0)));

// ll dp[1005][3] = {99999999};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    ll n = s.size();
    vec a(n + 1, 0), b(n + 1, 0);
    ll cnt = 0;
    rep(i, 0, n) {
        if (s[i] == '<') {
            cnt++;
        } else {
            cnt = 0;
        }
        a[i + 1] = cnt;
    }
    cnt = 0;
    for (ll i = n - 1; 0 <= i; --i) {
        if (s[i] == '>') {
            cnt++;
        } else {
            cnt = 0;
        }
        b[i] = cnt;
    }
    ll res = 0;
    rep(i, 0, n+1) {
        res += max(a[i],b[i]);
    }
    print(res);
    return 0;
}
