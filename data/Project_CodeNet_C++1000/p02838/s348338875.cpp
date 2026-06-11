/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll n;
cin>>n;
ll a[n];
for(ll i=0;i<n;i++)
{
cin>>a[i];
}
ll ans=0;
for(ll i=0;i<60;i++)
{
ll cnt=0;
for(ll o=0;o<n;o++)
{
if(a[o] & (1ll<<i))
{
cnt++;
}
}
ll k=(cnt*(n-cnt))%mod;
ll h=(1ll<<i);
h%=mod;
ll res=(h*k)%mod;
ans=(ans+res)%mod;
}
cout<<ans%mod;
}