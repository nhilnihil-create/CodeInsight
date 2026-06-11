#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mod_pow(ll n, ll p, ll mod){
    n %= mod;
    // return (n^p) % mod
    if(p==0) return 1;
    ll res = mod_pow(n*n%mod, p/2, mod);
    if(p%2==1) res = res * n % mod;
    return res;
}

int main(){
    int N;  cin >> N;
    vector<ll> D(N);
    for(int i=0; i<N; i++)
        cin >> D[i];
    if(D[0] != 0){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> cnt(N, 0);
    ll d = 0;
    for(int i=0; i<N; i++){
        cnt[D[i]]++;
        d = max(d, D[i]);
    }
    if(cnt[0] != 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1; i<=d; i++){
        if(cnt[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 1;
    ll mod = 998244353;
    for(int i=1; i<=d; i++){
        ll m = mod_pow(cnt[i-1], cnt[i], mod);
        ans *= m;
        ans %= mod;
    }
    cout << ans%mod << endl;
}
