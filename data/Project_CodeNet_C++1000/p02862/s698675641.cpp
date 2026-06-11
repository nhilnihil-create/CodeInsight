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
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define pb push_back
#define sz size()
#define SMX 2000000

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

//Combination MOD
const ll MOD = 1e9 + 7;
vector<ll> fac(SMX);
vector<ll> fac_inv(SMX);

ll mpow(ll x, ll n){
    if(n < 0)return 0;
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

void preComb(){
    fac[0] = 1;
    fac_inv[0] = 1;
    for(ll i = 0; i < SMX; i++){
        fac[i + 1] = fac[i] * (i + 1) % MOD;
        fac_inv[i + 1] = fac_inv[i] * mpow(i + 1, MOD - 2) % MOD;
    }
}

int main(){
    ll x, y;
    cin >> x >> y;
    if((x + y) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }

    int n= (x + y) / 3;
    x -= n;y -= n;
    preComb();
    ll res = comb(x + y, y) % MOD;
    if(res < 0)res += MOD;
    cout << res << endl;
}