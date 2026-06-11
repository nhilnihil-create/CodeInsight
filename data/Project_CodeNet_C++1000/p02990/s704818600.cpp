#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;



//Combination MOD
const ll MOD = INF + 7;
vector<ll> fac(300000);
vector<ll> fac_inv(300000);

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n & 1)ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0 || b < 0)return 0;

    ll tmp = fac_inv[a - b] * fac_inv[b] % MOD;
    return tmp * fac[a] % MOD;
}


int main(){
    ll n, k;
    cin >> n >> k;


    fac[0] = 1;
    fac_inv[0] = 1;
    for(ll i = 0; i < 300000; i++){
        fac[i + 1] = fac[i] * (i + 1) % MOD;
        fac_inv[i + 1] = fac_inv[i] * mpow(i + 1, MOD - 2) % MOD;
    }

    REP(i, 1, k){
        ll res;
        
        res = comb(n - k + 1, i) * comb(k - 1, i - 1) % MOD;
        
        cout << res << endl;
    }

}


