#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll modPow(ll n, ll p, ll mod) {
    n %= mod;
    // return (n^p) % mod
    if (p == 0)
        return 1;
    ll res = modPow(n * n % mod, p / 2, mod);
    if (p % 2 == 1)
        res = res * n % mod;
    return res;
}

int main() {
    string L;
    cin >> L;
    int N = L.length();

    ll ans = 0;
    ll mod = 1e9 + 7;
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        if (L[i] == '1') {
            ll temp = modPow(2, cnt, mod);
            temp = (temp * modPow(3, N - i - 1, mod)) % mod;
            ans = (ans + temp) % mod;
        }
        cnt += L[i] - '0';
    }

    ans = (ans + modPow(2, cnt, mod)) % mod;
    cout << ans << endl;
}
