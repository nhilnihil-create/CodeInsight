#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr ll  MOD = (1e9+7);
constexpr int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
constexpr int lcm(int a, int b) { return a / gcd(a, b) * b; }

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll factorial(ll n, ll m=2) {
    // calculate n!
    m = max(2LL, m);
    ll rtn = 1;
    for (ll i=m; i<=n; i++) {
        rtn = (rtn * i) % MOD;
    }
    return rtn;
}
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, p; cin >> n >> p;
    string s; cin >> s;
    ll res = 0;
    if (p==2 || p==5) {
        rep(i, n) {
            if ((s[i] - '0') % p == 0) res += i+1;
        }
    } else {
        int m = 1;
        vector<int> mods(n);
        vector<ll> cnt(p, 0);
        cnt[0] = 1ll;
        ll val = 0;
        for (int i=n-1; i>=0; --i) {
            val += m * (s[i]-'0');
            val %= p;
            cnt[val]++;
            m = 10 * m % p;
        }
        rep(i, p) res += cnt[i] * (cnt[i]-1) / 2;
    }
    cout << res << endl;
}
