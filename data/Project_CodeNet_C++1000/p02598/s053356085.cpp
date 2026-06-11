#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i=0; i < (ll)(n); i++)

int main(void){
    ll n,k;
    ll a[200005];
    cin>>n>>k;
    ll mx=0;
    rep(i,n){
        cin>>a[i];
        mx = max(mx,a[i]);
    }

    ll l=1,r=mx;
    ll ans=1000000001;
    while(l<=r){
        ll mid=(l+r)/2;
        ll total=0;
        rep(i,n){
            total+=a[i]/mid+(a[i]%mid!=0)-1;
        }
        if(total<=k){
            ans=min(ans,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout << ans << endl;
}