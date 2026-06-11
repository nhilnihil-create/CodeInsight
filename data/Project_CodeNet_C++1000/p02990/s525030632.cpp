#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    vector<ll> fact(2005);
    fact[0] = 1; fact[1] = 1;
    for (int i = 2; i < 2005; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }

    vector<ll> inv(2005); inv[1] = 1;
    for (int i = 2; i < 2005; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    vector<ll> invfact(2005);
    invfact[0] = 1; invfact[1] = 1;
    for (int i = 2; i < 2005; i++) {
        invfact[i] = invfact[i-1] * inv[i] % MOD;
    }       

    ll N, K; cin >> N >> K;

    ll tmp;
    for (ll i = 1; i <= K; i++) {
        if(N-K+1 < i){
            printf("0\n"); continue;
        }
        if(K < i){
            printf("0\n"); continue;
        }
        tmp = fact[N-K+1] * invfact[i] % MOD;
        tmp = tmp * invfact[N-K-i+1] % MOD;
        tmp = tmp * fact[K-1] % MOD;
        tmp = tmp * invfact[i-1] % MOD;
        tmp = tmp * invfact[K-i] % MOD;
        printf("%lld\n", tmp % MOD);
    }

}
