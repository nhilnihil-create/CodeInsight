//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;


vector<ll> inv,fac;

void inverse(ll n){
    //要素数:n+1 (0~n)
    inv[0]=1;
    inv[1]=1;
    for(ll i=2;i<=n;i++){
        inv[i]=(MOD-inv[MOD%i]*(MOD/i))%MOD;
    }
}

void inverse_u(ll n){
    //要素数:n+1 (0~n)
    for(ll i=2;i<=n;i++){
        inv[i]=(inv[i]*inv[i-1])%MOD;
    }
}

void factorial(ll n){
    //要素数:n+1 (0~n)
    fac[0]=1;
    fac[1]=1;
    for(ll i=2;i<=n;i++){
        fac[i]=(fac[i-1]*i)%MOD;
    }
}

ll nCr(ll n,ll r){
    return fac[n]*inv[r]%MOD*inv[n-r]%MOD;
}

ll proinverse(ll x,ll m){
    ll res=1,M=m-2;
    while(M>0){
        if(M&1) res=res*x%m;
        x=x*x%m;
        M>>=1;
    }
    return res;
}

void init_nCr(ll n){
    inv.assign(n+1,0);
    fac.assign(n+1,0);
    inverse(n); inverse_u(n);
    factorial(n);
}

int main(){
    ll n,k; cin>>n>>k;
    init_nCr(n);
    for(ll i=1;i<=k;i++){
        if(i>n-k+1){
            printf("0\n");
            continue;
        }
        ll ans=1;
        ans=(ans*nCr(n-k+1,i))%MOD;
        ans=(ans*nCr(k-1,i-1))%MOD;
        printf("%lld\n",(ans+MOD)%MOD);
    }
}