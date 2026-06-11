#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef pair<int, int> P;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a / b % MOD;
// (a % MOD) * modinv(b, MOD) % MOD
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    ll res = modpow(2, n, MOD) - 1;
    if (res < 0) res += MOD;

    ll A = 1, B = 1, dA = 1, dB = 1;
    rep(i, a) {
        A *= (n - i);
        A %= MOD;
        dA *= (a - i);
        dA %= MOD;
    }
    rep(i, b) {
        B *= (n - i);
        B %= MOD;
        dB *= (b - i);
        dB %= MOD;
    }

    A = (A % MOD) * modinv(dA, MOD) % MOD;
    B = (B % MOD) * modinv(dB, MOD) % MOD;

    res -= A;
    if (res < 0) res += MOD;
    res -= B;
    if (res < 0) res += MOD;
    cout << res << endl;

    return 0;
}