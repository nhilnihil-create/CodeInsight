#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll bunshi(ll n, ll a, ll mod) {
    ll res = 1;
    while (a > 0) {
        res *= n;
        n--;
        a--;
        res %= mod;
    }
    return res;
}

ll bunbo(ll a, ll mod) {
    ll res = 1;
    for (int i = a; i > 0; i--) {
        res *= i;
        res %= mod;
    }

    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;
    ll MOD = pow(10, 9) + 7;
    ll whole = modpow(2, n, MOD) - 1;

    ll abunshi = bunshi(n, a, MOD);
    ll abunbo = bunbo(a, MOD);
    ll bbunshi = bunshi(n, b, MOD);
    ll bbunbo = bunbo(b, MOD);

    ll nca = abunshi * modpow(abunbo, MOD - 2, MOD) % MOD;
    ll ncb = bbunshi * modpow(bbunbo, MOD - 2, MOD) % MOD;

    ll ans = whole - nca - ncb;
    if (ans < 0) {
        while (ans < 0)
            ans += MOD;
    }
    cout << ans << endl;
}