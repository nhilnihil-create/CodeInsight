#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#define MOD 1000000007
struct Mcomb {
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
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    ll ncr(int n, int r){
        if (n < r) return 0;
        if (n < 0 || r < 0) return 0;
        return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
    }

    ll npr(int n, int r){
        if(n < r)return 0;
        if(n < 0 || r < 0)return 0;
        return (fac[n] * inv[n - r]) % MOD;
    }

};

int main()
{
    Mcomb comb(10000);
    int n, blue;
    cin >> n >> blue;
    int red = n - blue;

    for(int i = 1; i <= blue; i++){
        
        ll cur = comb.ncr(blue - 1, i - 1);
        cur %= MOD;
        //cerr << "cur : " << cur << " curred : " << red - (i - 1) << endl; 
        cur *= comb.ncr(red - (i - 1) + i, i);
        cur %= MOD;
        cout << cur << endl;
    }
}