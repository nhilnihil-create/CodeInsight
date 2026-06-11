#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
ll n,k;
vector<ll>a((ll)3e5);
bool isOK(ll x){
    ll c=0;
    rep(0,i,n){
        c+=(a[i]+x-1)/x-1;
        if(c>k){
            return false;
        }
    }
    return true;
}
int main(void){
    cin>>n>>k;
    rep(0,i,n)cin>>a[i];
    ll ng=1,ok=2e9;
    if(isOK(1)){
        cout<<1;
        return 0;
    }
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(isOK(mid))ok=mid;
        else ng=mid;
    }
    cout<<ok;
}