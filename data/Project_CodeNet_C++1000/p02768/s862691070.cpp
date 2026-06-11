//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e9+7;
ll INF=1e10;

ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P==1) return N%M;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return (N * RepeatSquaring(N, P-1, M))%M;
}

int main(){
    ll n,a,b; cin>>n>>a>>b;
    a=min(a,n-a);
    b=min(b,n-b);
    ll ans=RepeatSquaring(2,n,mod)-1;
    ll xa=1,ya=1;
    rep(i,a){
        xa*=n-(i);
        xa%=mod;
        ya*=i+1;
        ya%=mod;
    }
    ya=RepeatSquaring(ya,mod-2,mod);
    ll A=xa*ya%mod;
    ll xb=1,yb=1;
    rep(i,b){
        xb*=n-i;
        xb%=mod;
        yb*=i+1;
        yb%=mod;
    }
    yb=RepeatSquaring(yb,mod-2,mod);
    ll B=xb*yb%mod;
    ans-=(A+B);
    ans%=mod;
    if(ans<0)ans+=mod;
    cout<<ans<<endl;


}

























































































