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

void inverse(ll n,vector<ll> &inv){
    //要素数:n+1 (0~n)
    inv[0]=1;
    inv[1]=1;
    for(ll i=2;i<=n;i++){
        inv[i]=(MOD-inv[MOD%i]*(MOD/i))%MOD;
    }
}

void inverse_u(ll n,vector<ll> &inv){
    //要素数:n+1 (0~n)
    for(ll i=2;i<=n;i++){
        inv[i]=(inv[i]*inv[i-1])%MOD;
    }
}

void factorial(ll n,vector<ll> &fac){
    //要素数:n+1 (0~n)
    fac[0]=1;
    fac[1]=1;
    for(ll i=2;i<=n;i++){
        fac[i]=(fac[i-1]*i)%MOD;
    }
}

ll nCr(ll n,ll r,vector<ll> &inv,vector<ll> &fac){
    return fac[n]*inv[r]%MOD*inv[n-r]%MOD;
}

int main(){
    ll n,k; cin>>n>>k;
    vector<ll> inv(n+1,0),fac(n+1,0);
    inverse(n,inv); inverse_u(n,inv);
    factorial(n,fac);
    for(ll i=1;i<=k;i++){
        if(n-k+1<i){
            cout<<0<<endl;
            continue;
        }
        ll ans=1;
        ans=(ans*nCr(k-1,i-1,inv,fac))%MOD;
        ans=(ans*nCr(n-k+1,i,inv,fac))%MOD;
        cout<<(ans+MOD)%MOD<<endl;
    }
}