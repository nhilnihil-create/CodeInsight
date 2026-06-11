#include <bits/stdc++.h>
#define ll  int
using namespace std;
int main() {
    ll n,d;
    cin>>n>>d;
    ll a[n][d];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<d;j++)cin>>a[i][j];
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll r=0;
            for(ll k=0;k<d;k++){
                r+=(a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
            }
            long double r1=sqrt(r);
            
            if(r1-floor(sqrt(r))==0)ans++;
        }
    }
    cout<<ans<<"\n";
    
}

