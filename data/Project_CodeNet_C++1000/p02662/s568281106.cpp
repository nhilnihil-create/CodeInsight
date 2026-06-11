#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
static const ll MOD=998244353;

ll mod_pow(ll x, ll n){ //べき乗
    ll ans=1;
    x%=MOD;
    while(n!=0){
        if(n&1) ans=ans*x%MOD;
        x=x*x%MOD;
        n=n>>1;
    }
    return ans%MOD;
}


int main(){
    int N,S; cin >> N >> S;
    ll a[N];
    for(int i=0;i<N;i++) cin >> a[i];
    ll dp[N+1][S+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=mod_pow(2,N);
    for(int i=0;i<N;i++){
        for(int j=0;j<=S;j++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=MOD;
            if(j+a[i]>S) continue;
            dp[i+1][j+a[i]]+=(dp[i][j]*mod_pow(2,MOD-2))%MOD;
            dp[i+1][j+a[i]]%=MOD;
        }
    }
    cout << dp[N][S]%MOD << endl;
}