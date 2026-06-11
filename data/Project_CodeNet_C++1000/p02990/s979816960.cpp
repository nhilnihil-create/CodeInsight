#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;
 
const ll M = 1000000007;
 
vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

int main(){
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    ll N, K; cin >> N >> K;
    if(N==K){
        for(int i=1; i<K+1; i++){
            if(i==1){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
    else{
    for(int i=1; i<K+1; i++){
        if(N-K<i-1){
            cout << 0 << endl;
        }
        else{
            ll res = 0;
            if(N-K>=i+1){
            res += comb(K-1, i-1)*comb(N-K-1,i);
            res %= M;
            }
            if(i>1){
            res += comb(K-1, i-1)*comb(N-K-1,i-2);
            res %= M;
            }
            if(N-K>=i){
            res += 2*comb(K-1, i-1)*comb(N-K-1,i-1);
            res %= M;
            }
            cout << res << endl;
        }
    }
    }
}