#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll n;
cin>>n;
vector<pair<ll,ll> > vc;
ll x,y;
for(ll i=0;i<n;i++)
{
cin>>x>>y;
vc.push_back({y,x});
}
sort(vc.begin(),vc.end());
ll s=0;
string ans="Yes";
for(ll i=0;i<n;i++)
{
if(s+vc[i].second>vc[i].first)
{
ans="No";
break;
}
s+=vc[i].second;
}
cout<<ans<<endl;
}