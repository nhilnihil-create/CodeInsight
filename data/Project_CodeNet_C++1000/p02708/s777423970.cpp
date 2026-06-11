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
#include<cassert>
#include<cmath>
#include<cstdint>

#define INF 1e9
#define LINF 1e19
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
     
const ll MOD = 1e9 + 7;
const ll zer = 0;

//----------------------------------------------
ll mx;
vector<ll> fac(200005);
vector<ll> ifac(200005);

//modpow
ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

//二項係数を求める
ll comb(ll a, ll b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0 || b < 0)return 0;
    ll tmp = ifac[a - b] * ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

//facとifacの前処理
void pre_comb(ll n){
    fac[0] = 1;
    ifac[0] = 1;
    rep(i, n){
        fac[i + 1] = fac[i] * (i + 1) % MOD;
        ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD;
    }
}
//----------------------------------------------

int main(){
    ll n, k;
    cin >> n >> k;
    ll l = 0, r = 0;
    ll res = 0;
    rep(i, k){
      l += i;
      r += (n - i);
    }
    REP(i, k, n + 1){
      res = (res + r - l + 1) % MOD;
      l += i;
      r += (n - i);
    }
  cout << res << endl;
}



