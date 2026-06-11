#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using bint = boost::multiprecision::cpp_int;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repSE(i,s,n) for (int i = (s); i < (n); i++)
#define rrepSE(i,s,e) for (int i = (s); i > (e); i--)
#define ssort(v) sort(v.begin(), v.end())
#define gsort(v) sort(v.rbegin(), v.rend())
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
#define DEBUG_PRINT(var) std::cout << #var << " = " << var << "\n";

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i,n+1) cin >> a[i];
    if (n == 0) {
        if (a[0] == 1) { cout << 1 << "\n"; return 0; }
        else { cout << -1 << "\n"; return 0; }
    }
    // cout << "a: " << a << "\n";
    vector<ll> ar(n+2);
    ar[n+1] = 0;
    rrepSE(i, n, -1) {
        ar[i] = ar[i+1] + a[i];
    }
    // cout << "ar: " << ar << "\n";
    vector<ll> b(n+1);
    b[0] = 1 - a[0];
    repSE(i,1,n+1) {
        if (2*b[i-1] < a[i]) { cout << -1 << "\n"; return 0; }
        b[i] = min(2*b[i-1] - a[i], ar[i+1]);
        // if (b[i] + a[i] < b[i-1]) { cout << -1 << "\n"; return 0; }
    }
    // cout << "b: " << b << "\n";
    ll ans = 0;
    rep(i,n+1) ans += a[i] + b[i];
    cout << ans << "\n";
    return 0;
}
