#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

const int MAX_N = 10000;

ll fact[MAX_N+100];
ll frev[MAX_N+100];

ll rev(ll a, ll p){
    if(p == 0) return 1;
    ll tmp = rev(a, p/2);
    tmp = tmp * tmp % MOD;
    if(p % 2 == 1) tmp = tmp * a % MOD;
    return tmp;
}


void calc_fact(){
    fact[0] = frev[0] = 1;
    for(int i = 1; i <= MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        frev[i] = rev(fact[i], MOD-2);
    }
}


ll comb(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 || k == 0) return 1;
    return fact[n] * frev[k] % MOD * frev[n-k] % MOD;
}


int main(){
    ll N, K;
    cin >> N >> K;

    //in main function
    fact[0] = frev[0] = 1;
    for(int i = 1; i <= MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        frev[i] = rev(fact[i], MOD-2);
    }

    REPi(i,1,K+1){
        ll ans = comb(N-K+1, i) * comb(K-1, i-1);
        cout << ans % MOD << endl;
    }
    return 0;
}
