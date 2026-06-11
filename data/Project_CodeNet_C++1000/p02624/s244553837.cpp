#include <bits/stdc++.h>
#define ll long long
#define fr(i,n) for(ll i=0;i<n;i++)
using namespace std;
const ll mod=1e6+7;


int main() {
    ll n,ans=0;cin>>n;
    vector<ll> k(n+1,0);
for(ll i=1;i<=n;i++){
    k[i]++;
    for(ll j=i*2;j<=n;j+=i)
        k[j]++;
}
for(ll i=1;i<=n;i++){
    ans+=(1LL*i*k[i]);
}
cout<<ans;}

