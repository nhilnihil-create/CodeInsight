#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll=long long;
int main()
{
    ll n,ans=0;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    rep(i,n) for(ll j=i+1;j<n;j++) ans+=a[i]*a[j];
    cout<<ans;
}