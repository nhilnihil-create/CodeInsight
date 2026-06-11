/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
 * ABC147 F
 * ABC174 F
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
map<ll,ll> mp;
ll ans=0;
for(ll i=0;i<n;i++)
{
cin>>a[i];
mp[a[i]]++;
}
for(ll i=1;i<=n;i++)
{
if(mp[i]>0)
{
ans+=mp[i]*(mp[i]-1)/2;
}
}
for(ll i=0;i<n;i++)
{
ll h=ans;
h-=mp[a[i]]*(mp[a[i]]-1)/2;
h+=(mp[a[i]]-1)*(mp[a[i]]-2)/2;
cout<<h<<endl;
}
}



/*
 * ||||


 */