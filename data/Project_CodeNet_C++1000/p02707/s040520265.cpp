#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n;
    cin>>n;
    vector<ll>c(n);
    rep(0,i,n)c[i]=0;
    rep(1,i,n){
        ll a;
        cin>>a;
        --a;
        ++c[a];
    }
    rep(0,i,n)cout<<c[i]<<endl;
}
