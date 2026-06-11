//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

const int MAX=1000010;
ll fac[MAX],finv[MAX],inv[MAX];

void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll C(int n,int k){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}


int main(){
    ll x,y; cin>>x>>y;
    if(2*x-y<0||2*y-x<0||(2*x-y)%3!=0||(2*y-x)%3!=0){
        cout<<0<<endl;
        return 0;
    }
    ll n=(2*x-y)/3,m=(2*y-x)/3;
    COMinit();
    ll ans=C(n+m,n);
    cout<<ans<<endl;
}

























