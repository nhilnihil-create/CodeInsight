#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int MAX = 2000050;
const int mod = 1e9 + 7;

long long fac[MAX], finv[MAX], inv[MAX];

void combInit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

long long comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(){
    ll x, y; cin>>x>>y;
    if((x + y) % 3) cout<<0<<endl;
    else{
        ll z = (x + y) / 3;
        if(z > x || z > y) cout << 0 << endl;
        else{
            ll n = (x-z) + (y-z);
            ll r = (x-z);
            combInit();
            ll res = comb(n, r);
            cout << res << endl;
        }
    }
    return 0;
}