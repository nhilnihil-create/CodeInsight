#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
using ll=long long;
const ll MOD=1000000007,MOD2=998244353,INF=9223372036854775807;//INFはllの最大値で19桁

//nのp乗
ll power(ll n,ll p){
    if(p==0){return 1;}
    if(p%2==1){return n*power(n,(p-1)/2)%MOD*power(n,(p-1)/2)%MOD;}
    else{return power(n,p/2)*power(n,p/2)%MOD;}
}

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> num(K+1);
    rep(i,K+1){
        if(i==0)continue;
        num.at(i)=power(K/i,N);
    }
    for(ll i=K;i>0;i--){
        for(ll j=2;i*j<=K;j++){
            num.at(i)-=num.at(i*j);
            num.at(i)%=MOD;
        }
    }
    ll ans=0;
    rep(i,K+1){
        ans+=i*num.at(i)%MOD;
        ans%=MOD;
    }
    ans+=MOD;
    ans%=MOD;
    cout<<ans<<endl;
    //rep(i,K+1){cout<<num.at(i)<<" ";}
}
