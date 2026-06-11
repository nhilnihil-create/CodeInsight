#include<iostream>
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin>>n>>k;

    ll ans=0;
    for(ll i=k;i<=n+1;i++){
        ll l=(i-1)/2*i;
        ll r=(n-i+1+n)/2*i;
        ans+=r-l+1;
        ans%=1000000007;
    }
    cout<<ans<<endl;
}