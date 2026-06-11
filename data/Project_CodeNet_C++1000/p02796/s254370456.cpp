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
    for (int i = 0; i < v.size() - 1; ++i) {
        os << v[i] << " ";
    }
    if (v.size() > 0) {
        os << v[v.size() - 1] << endl;
    }
    return os;
}

ll extgcd(ll a, ll b, ll &x, ll &y) {  // extended Euclidean algorithm, used for
                                       // modular multiplicative inverse
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;  // return gcd(a,b)
}

ll mod_inv(ll a, ll m = MOD) {  // return inv(a) mod m, ax+my=gcd(a,m)=1, m is
                                // prime int, ax-1=mq equiv. ax-mq=1
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;  // From (possibly) negative x to positive x
}

vector<ll> fact, invfact;
void calc_fact(int n, ll m = MOD) {  // Calculate factorial up to n
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = invfact[0] = 1;
    REP(i, n) {
        fact[i + 1] = fact[i] * (i + 1) % m;
        invfact[i + 1] = invfact[i] * mod_inv(i + 1) % m;
    }
}
ll perm(int n, int k, ll m = MOD) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k] % m;
}
ll comb(int n, int k, ll m = MOD) {
    if (n < 0 || k < 0 || k > n) return 0;
    return (fact[n] * invfact[n - k] % m) * invfact[k] % m;
}

int main() {
    ll n;
    cin>>n;
    vll l(n), r(n);
    vector<pll> p(n);
    REP(i, n) {
        ll a, b;
        cin >> a >> b;
        p[i].second = a - b;
        p[i].first = a + b;
    }
    sort(p.begin(), p.end());
    ll now = LLONG_MIN, ans = 0;
    REP(i,n){
        if (p[i].second >= now){
            now = p[i].first;
            ++ans;
        }
    }
    cout << ans << endl;
}