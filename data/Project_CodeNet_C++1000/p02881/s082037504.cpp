#include<bits/stdc++.h>
#define ll long long 
using namespace std;
 
int main(){
    ll n;
    cin>>n;
    ll ans=1000000000005;
    for(ll i=1;i<=sqrt(n);i++){
        ll j=n/i;
        if(j*i==n) ans=min(ans,i+j-2);
    }
    cout<<ans<<"\n";
    return 0;
}