#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i=0; i < (ll)(n); i++)

int main(void){
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll p=n/i;
        ans+=i*(1+p)*p/2;
    }
    cout<<ans<<endl;
}