#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

ll modpow(ll a, ll n){
    ll res=1;
    while(n > 0){
        if(n & 1) res=res*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return res;
}

int main(){
    ll N, K;
    cin >> N >> K;
    ll res=0;
    vector<ll> dp(K+1);
    for(ll i=K; i>=1; i--){
        ll a=K/i;
        dp[i]=modpow(a, N);
        for(int j=2; j<=a; j++){
            dp[i]=(dp[i]-dp[j*i])%MOD;
        }
        res=(res+i*dp[i]%MOD)%MOD;
    }
    if(res < 0) res+=MOD;
    cout << res << endl;
    return 0;
}