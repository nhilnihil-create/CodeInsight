#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main()
{
    ll n;
    cin>>n;
    ll ans=n+2;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ll t=i+n/i-2;
            ans=min(ans,t);
        }
    }
    cout<<ans;
}