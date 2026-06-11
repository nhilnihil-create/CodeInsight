#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)

#define MOD 1000000007


using ll = long long;
using namespace std;

typedef vector<ll> vl;


ll mlpow(ll x, ll p) { //x^p(long long)%MOD
    ll tmp = 1;
    if(p == 0) return 1;
    while(p != 0) {
        if(p & 1) tmp = tmp*x % MOD;
        x = x*x % MOD;
        p = p >> 1;
    }
    return tmp;
}


int main() {
    int N;
    cin >> N;
    vl A(N);
    rep(i,N) cin >> A[i];

    ll ans = 0;
    int cnt = 0;
    bool flag = true;
    while(flag) {
        flag = false;
        ll num1 = 0, num0 = 0;
        rep(i,N){
            if(A[i]&1 == 1)num1++;
            else num0++;
            A[i] >>= 1;
            if(A[i] != 0) flag = true;
        }
        ll tmp = (mlpow(2,cnt)*((num0*num1)%MOD))%MOD;
        ans += tmp;
        ans %= MOD;
        cnt++;
    }

    cout << ans << "\n";
    return 0;
}
