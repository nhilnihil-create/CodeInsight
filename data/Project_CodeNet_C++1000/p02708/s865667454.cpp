#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,k;
    cin>>n>>k;
    ll ans=0;
    ll sum_min=0;
    ll sum_max=0;
    ll mod=pow(10,9)+7;
    rep(i, k-1){
        sum_min+=i;
        sum_max+=n-i;
    }
    for(int i=k-1;i<n+1;i++){
        sum_min+=i;
        sum_max+=n-i;
        ans+=sum_max-sum_min+1;
        ans%=mod;
    }
    cout<<ans<<endl;
}