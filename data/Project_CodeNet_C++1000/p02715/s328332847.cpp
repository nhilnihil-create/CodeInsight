#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = pow(10,9) + 7;

ll modpow(ll a, ll b, ll mod = MOD) {
   ll res = 1;
   for (a %= mod; b; a = a * a % mod, b >>= 1)
     if (b & 1) res = res * a % mod;
   return res;
 }

//E
int main()
{
    ll N,K;
    ll sum=0;
    cin >> N >> K;
    vector<ll> res(K,1);

    for(int n=K; n>0; --n){
        int a=K/n;
        res[n-1]=modpow(a,N);
        for(int j=2; j<=K/n; ++j){
            res[n-1] -= res[j*n-1];
        }
    }
    
    rep(i,K){
        ( sum += res[i]*(i+1) );
    }

    cout << sum%MOD << endl;
    return 0;
}