#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll minv=1000000000005;
    for(ll i=1;i<=sqrt(n);i++){
        ll j=n/i;
        if(j*i==n) minv=min(minv,i+j-2);
    }
    cout<<minv<<"\n";
    return 0;
}
