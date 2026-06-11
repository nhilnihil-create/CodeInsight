// g++ -std=c++17 -O2 -Wall C.cpp -o C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

ll powmod(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll ans = powmod(10, n) - powmod(9, n) - powmod(9, n) + powmod(8, n);
    ans %= MOD;
    ans = (ans + MOD) % MOD;
    cout << ans;
}