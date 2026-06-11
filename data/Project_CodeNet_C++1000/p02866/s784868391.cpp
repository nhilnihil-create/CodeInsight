#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
ll modinv(ll a, ll m) {
    ll x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}

// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main() {
    int N; cin >> N;
    map<int, int> M;
    int ma = -1;
    rep(i,N) {
        int d; cin >> d;
        if (i == 0 && d != 0) { // Added at the end. This is REQUIRED.
            cout << 0 << endl;
            return 0;
        }
        M[d]++;
        if (ma < d) ma = d;
    }
    if (M[0] != 1) { // This is not enough. The first and only first should be 0
        cout << 0 << endl;
        return 0;
    }
    ll res = 1;
    for (int i = 1; i <= ma; i++) {
        if (M[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
        res *= modpow(M[i], M[i+1], 998244353);
        res %= 998244353;
    }
    cout << res << endl;
}
