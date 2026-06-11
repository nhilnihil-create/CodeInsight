#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

const ll ln=1000000007;

ll sum(ll l,ll r){
    return (l+r)*(r-l+1)/2;
}

int main(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=k;i<=n+1;i++){
        ll l=sum(0,i-1), r=sum(n-i+1,n);
        ans+=r-l+1;
        if(ans>=ln)ans=ans%ln;
    }
    cout<<ans<<endl;
}