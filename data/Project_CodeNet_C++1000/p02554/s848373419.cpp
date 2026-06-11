#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll MOD = 1000000007;

ll powmod(ll x,ll n) {
    ll res = 1;
    for(int i = 0;i < n;i++) {
        res = res * x % MOD;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ans = powmod(10,n) - powmod(9,n) - powmod(9,n) + powmod(8,n);
    ans%=MOD;
    ans = (ans+MOD)%MOD;
    cout << ans << endl;
}
