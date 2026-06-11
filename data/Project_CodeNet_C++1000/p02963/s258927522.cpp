#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i< (n);i++)
#define rep1(i,n) for(int i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const static ll MOD = (1e+9);

ll modpow(ll a,ll n){
    if(n==0)return 1;
    if(n%2==1)return a*modpow(a,n-1)%MOD;
    ll t = modpow(a,n/2) % MOD;
    return t*t % MOD;
}
ll get_s(ll a,ll b,ll c, ll d,ll e, ll g){
    ll x1 = c-a,x2 = e-a,y1 = d-b,y2 = g-b;
    return(abs(x1*y2-x2*y1));
}

int main(){
    ll S;cin>>S;
    ll y = (S%MOD == 0 ? S/MOD:S/MOD+1);
    ll x = abs(y*MOD-S);
    cout<<0<<' '<<0<<' '<<MOD<<' '<<1<<' '<<x<<' '<<y<<endl;
    return 0;
}