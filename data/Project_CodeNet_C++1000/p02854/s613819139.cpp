#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> sum(n+1,0);
    rep(i,n){
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
    }
    ll minv=2020202020;
    for(int i=1;i<n;i++) minv=min(minv,abs(2*sum[i]-sum[n]));
    cout<<minv<<"\n";
    return 0;
}
