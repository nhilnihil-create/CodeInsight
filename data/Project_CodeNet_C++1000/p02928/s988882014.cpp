#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

const int mod=1e9+7;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    int cnt=0,cnt2=0;
    rep(i,n){
        for(int j=i+1; j<n; ++j){
            if(a[i]>a[j])cnt++;
        }
    }
    rep(i,n){
        rep(j,n){
            if(a[i]>a[j])cnt2++;
        }
    }
    ll ans=cnt*k;
    ans%=mod;
    ans+=cnt2*((k*(k-1)/2)%mod);
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}
