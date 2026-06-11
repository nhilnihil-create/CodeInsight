#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
typedef long long ll;

ll modPow(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a % MOD;
    if(n%2 == 1)return (a * modPow(a, n-1))%MOD;
    ll m = modPow(a, n/2);
    return (m * m) % MOD;
}


int main() {
    ll n, a, b;cin >> n >> a >> b;
    ll cha, chb;
    ll x = n, y = a;
    for (int i = 1; i < a; i++)x = (x * (n-i)) % MOD;
    for (int i = 1; i < a; i++)y = (y * (a-i)) % MOD;
    cha = (x * modPow(y, MOD-2)) % MOD;
    x = n, y = b;
    for (int i = 1; i < b; i++)x = (x * (n-i)) % MOD;
    for (int i = 1; i < b; i++)y = (y * (b-i)) % MOD;
    chb = (x * modPow(y, MOD-2)) % MOD;
    ll ans = (modPow(2, n) - 1 - cha - chb + MOD * 2) % MOD ;
    cout << ans << endl;
    return 0;
}