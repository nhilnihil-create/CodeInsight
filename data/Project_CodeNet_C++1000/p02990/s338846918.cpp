#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

ll modpow(ll A, ll N) {
    ll RET = 1;
    // 例えば3=101(2)なので、下位bitから順に1ならa倍する
    while (N) {
        if (N & 1) RET = RET * A % mod;
        A = A * A % mod;
        N >>= 1;
    }
    return RET;
}

int main() {
    ll n,k;
    cin >> n >> k;
    ll c1[k];
    ll c2[k];
    c1[0] = n-k+1;
    c2[0] = 1;
    rep(i,k-1) {
        c1[i+1] = c1[i] * (n-k-i) % mod * modpow(i+2, mod-2) % mod;
        c2[i+1] = c2[i] * (k-1-i) % mod * modpow(i+1, mod-2) % mod;
    }
    rep(i,k) cout << c1[i] * c2[i] % mod << endl;
    return 0;
}
