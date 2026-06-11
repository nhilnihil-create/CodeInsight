#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll X[100100];

ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}


int main(){
    ll N, K;
    cin >> N >> K;
    for(ll k = K; k >= 1; k--){
        ll x = mod_pow(K/k, N, MOD);
        for(ll m = 2*k; m <= K; m += k){
            x += MOD - X[m];
            x %= MOD;
        }
        X[k] = x;
    }

    ll ans = 0;
    REPi(k,1,K+1){
        ans += k*X[k];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
