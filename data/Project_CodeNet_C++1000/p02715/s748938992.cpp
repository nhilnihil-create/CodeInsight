#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

// nのk乗を計算する
ll modpow(ll n, ll k){
    ll ret = 1;
    ll t = n;
    while(k > 0){
        if(k & 1) ret = ret * t % MOD;
        t = t * t % MOD;
        k = k>>1;
    }
    return ret;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> f(K+1);
    ll tmp;
    for (ll i = K; i >= 1; i--) {
        tmp = modpow(K/i, N);
        for (ll j = 2; j <= K/i; j++) {
            tmp = (MOD + tmp - f[i*j]) % MOD;
        }
        f[i] = tmp;
    }
    ll ans = 0;
    for (ll i = 1; i <= K; i++) {
        tmp = f[i] * i % MOD;
        ans = (ans + tmp) % MOD;
    }
    printf("%lld\n", ans);

    

}