#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

ll powll(ll base,ll exp) { ll res = 1; while(exp>0){ if(exp & 1)res = res * base; base = base * base; exp >>= 1; } return res;}
ll mod_pow(ll base,ll exp) { ll res = 1; while(exp>0){ if(exp & 1)res = res * base % mod; base = base * base % mod; exp >>= 1; } return res % mod;}

ll modinv(ll a) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}


class Mcomb {
public:
    vector<ll> fac;
    vector<ll> inv;
    vector<ll> finv;
    //nCnまで対応できる
    Mcomb(int n) {
        fac.resize(n + 1), inv.resize(n + 1), finv.resize(n + 1);
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i <= n; i++){
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod%i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
 
    ll ncr(int n, int r){
        if (n < r) return 0;
        if (n < 0 || r < 0) return 0;
        return fac[n] * (finv[r] * finv[n - r] % mod) % mod;
    }
 
    ll npr(int n, int r){
        if(n < r)return 0;
        if(n < 0 || r < 0)return 0;
        return (fac[n] * inv[n - r]) % mod;
    }
 
};
Mcomb comb(2000000);

 
ll ncr(int n, int r) {
   ll res = 1;
   for (int i = n - r + 1; i <= n; i++) res = res * i % mod;
   for (int i = 1; i <= r; i++) res = res * modinv(i) % mod;
   return res;
}

int main()
{
    int x, y; cin >> x >> y;
    if((x + y) % 3) {
        cout << 0 << endl;
        return 0;
    }
    int n = (x + y) / 3;
    x -= n, y -= n;
    if(x < 0 || y < 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << comb.ncr(n, x) << endl;

}