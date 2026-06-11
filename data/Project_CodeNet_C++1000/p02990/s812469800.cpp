#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(cnt,e) for(ll cnt=0;cnt<e;cnt++ )
typedef pair<ll,ll> P;
const ll mod = 1e9+7;
const ll INF = INT64_MAX;


ll i,j,k;
ll kaijou[2000+1];
ll gyakugen[2000+1];
long long ruijou(long long x, long long y){
    if(y==0) return 1;
    else if(y%2==0) return ruijou(x*x%mod,y/2);
    else return x*ruijou(x,y-1)%mod;
}

ll combination(ll n,ll c){
    if(n<c)return 0;
    return ((kaijou[n]*gyakugen[c])%mod)*gyakugen[n-c]%mod;
}
ll mo(ll x){
    ll ans=x%mod;
    if(x>=0)return ans;
    return ans+mod;
}


int main(){
    ll N,K;
    cin>>N>>K;
    V kaisuu(K);
    rep(i,N+1){
        if(i==0)kaijou[i]=1;
        else kaijou[i]=(kaijou[i-1]*i)%mod;
    }
    rep(i,N+1){
        if(i==0)gyakugen[i]=1;
        else gyakugen[i]=(gyakugen[i-1]*ruijou(i,mod-2))%mod;
    }

    rep(i,K){
        cout<<mo(combination(N-K+1,i+1)*combination(K-1,i))<<endl;
    }

}
