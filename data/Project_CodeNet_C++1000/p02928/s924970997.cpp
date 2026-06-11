#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll mod=1e9+7;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int ct1=0;
        int ct2=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            ct1++;
        }
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            ct2++;
        }
        ll p=((k*(k-1))/2)%mod;
        ll q=((k*(k+1))/2)%mod;
        ans=(ans+ct1*p)%mod;
        ans=(ans+(ct2*q))%mod;
    }
    cout<<ans<<endl;
    
}