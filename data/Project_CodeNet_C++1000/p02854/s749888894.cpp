#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main()
{
    ll n,all=0,sum=0;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        all+=a[i];
    }
    ll ans=all;
    rep(i,n){
        sum+=a[i];
        all-=a[i];
        ans=min(abs(all-sum),ans);
    }
    cout<<ans;
}