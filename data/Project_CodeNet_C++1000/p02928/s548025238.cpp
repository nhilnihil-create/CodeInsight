#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
const ll mod=1e9+7;
int main(void){
    // Your code here!
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    rep(0,i,n){
        cin>>v[i];
    }
    ll ans=0;
    rep(0,i,n){
        ll r=0,a=0;
        rep(i+1,j,n)if(v[i]>v[j])++r;
        rep(0,j,n)if(v[i]>v[j])++a;
        ans+=r*k%mod;
        ans%=mod;
        ans+=k*(k-1)/2%mod*a%mod;
        ans%=mod;
    }
    cout<<ans;
}