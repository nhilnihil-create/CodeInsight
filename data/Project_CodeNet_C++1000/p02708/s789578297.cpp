#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    ll n,k;
    ll ans=0;
    ll a=1e9+7;
    cin>>n>>k;
    for(ll i=k;i<=n+1;i++){
        ans+=((n-i+1)*i+1)%a;
        //cout<<(n-i+1)<<" "<<i<<endl;
    }
    cout<<ans%a<<endl;
}