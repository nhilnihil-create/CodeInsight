#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;

#define MOD 1000000007

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll mod = pow(10, 9) + 7;

    string L;
    cin >> L;

    ll base = 1LL;
    ll ans = 0;

    for(ll i = 0; i < L.length(); i++) {
        if(L[i] == '0') continue;
        ll k = modpow(3LL, L.length() - i - 1LL, mod);
        k %= mod;
        k *= base;
        k %= mod;
        base *= 2LL;
        base %= mod;
        ans += k;
        ans %= mod;
    }

    ans += base;
    ans %= mod;

    cout << ans << endl;
}