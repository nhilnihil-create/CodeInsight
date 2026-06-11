#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

const ll MOD = pow(10, 9) + 7;

// a^n mod を計算する
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

ll comb(ll n, ll k){
  ll x = 1;
    for(int i=n; i >= n-k+1; i--) {
        x = x*i%MOD;
    }

    ll y = 1;
    for(int i=1; i<=k; i++) {
        y = y*i%MOD;
    }
    y = modpow(y, MOD-2);

    return x*y%MOD;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll nCa = comb(n, a);
    ll nCb = comb(n, b);
    ll ans = (modpow(2, n) - 1 - nCa - nCb) % MOD;
    while(ans < 0){
        ans += MOD;
    }
    cout <<  ans << endl;
}