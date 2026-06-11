#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main()
{
    ll n,ans=0;
    cin>>n;
    map<ll,ll> mp;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n!=1) mp[n]++;
    for(auto p:mp){
        ll i=1;
        while(p.second-i>=0){
            p.second-=i;
            i++;
            ans++;
        }
    }
    cout<<ans<<endl;
}