#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll mod=1e9+7;

//RepeatSquare
ll RS(ll N ,ll P, ll M){
    if(P==0) return 1;
    else if(P%2==0){
        ll t=RS(N,P/2,M);
        return t*t%M;
    }
    else return N*RS(N,P-1,M)%mod;   
}
//combination
ll f[10010],inv[10010];

void init(){
    f[0]=inv[0]=1;
    for(int i=1;i<10010;i++){
        f[i]=f[i-1]*i%mod;
        inv[i]=RS(f[i],mod-2,mod);
    } 
}

ll comb(ll a,ll b){
    if(b>a) return 0;
    else return f[a]*inv[b] % mod *inv[a-b]% mod;
}

int main(){
    init();
    ll N,K;cin>>N>>K;
    for(int i=1;i<=K;i++){
        ll t =comb(K-1,i-1)*comb(N-K+1,i)%mod;
        cout << t <<endl;
    } 
    //cout << f[2000] << endl;
}