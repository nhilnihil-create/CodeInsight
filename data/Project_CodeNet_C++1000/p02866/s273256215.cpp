#include<bits/stdc++.h>
using namespace std;

#define ll  long long

const int N=1e5+9;
ll mod=998244353;
ll modpow(ll a,ll n){
    ll sum=a,ret=1;
    while (n > 0){
        if (n & 1)
            ret=sum*ret%mod;
        n/=2;
        sum=sum*sum%mod;
    }
    return ret;
}
int main()
{
    int x;
    cin>>x;
    vector<int>v(x);
    map<int,int>m;
    for (int i=0;i<x;i++){
        cin>>v[i];
        m[v[i]]++;
    }
    if (m[0]!=1||v[0]!=0)
        cout<<0<<endl;
    else{
        ll ans=1;
        for (int i=1;i<x;i++){
            if (m[i]){
                ans=ans*modpow(m[i-1],m[i])%mod;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
