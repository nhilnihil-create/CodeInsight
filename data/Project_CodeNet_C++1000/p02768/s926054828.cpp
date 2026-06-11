#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

ll mod = 1e9 + 7;

ll modpow(ll a ,ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * a % mod;
        a = a * a % mod;
        n = n >> 1;
    }
    return res;
}

//aのmod mにおける逆元を求める
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;

    ll nCa = 1, nCb = 1;
    for(int i=0;i<a;i++){
        nCa *= n-i;
        nCa %= mod;
    }
    for(int i=1;i<=a;i++){
        nCa *= modinv(i, mod);
        nCa %= mod; 
    }
    for(int i=0;i<b;i++){
        nCb *= n-i;
        nCb %= mod;
    }
    for(int i=1;i<=b;i++){
        nCb *= modinv(i, mod);
        nCb %= mod; 
    }

    //cout << modpow(2, n) << " " << nCa << " " << nCb << endl;
    cout << (modpow(2, n) - 1 - nCa - nCb + 2*mod)%mod << endl;

}