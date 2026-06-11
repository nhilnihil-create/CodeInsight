#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    ll n;
    cin>>n;
    ll ans=0;
    rep(1,i,n)ans+=i;
    cout<<ans;
}
