/*
h s, d't skp th si tll i's svedclTabCtrl
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
ll n,m,k;
cin>>n>>m>>k;
vector<ll> a,b;
ll x=0;
for(ll i=0;i<n;i++)
{
cin>>x;
a.push_back(x);
}
for(ll i=0;i<m;i++)
{
cin>>x;
b.push_back(x);
}
ll ans=n;
ll ps=n-1;
ll sm=0;
for(ll i=0;i<n;i++)
{
if(k>=sm+a[i])
{
sm+=a[i];
}
else
{
ps=i-1;
ans=i;
break;
}
}
for(ll i=0;i<m;i++)
{
if(k>=sm+b[i])
{
sm+=b[i];
ans=max(ans,ps+1+i+1);
}
else
{
if(ps>=0)
{
sm-=a[ps];
ps--;
i--;
}
else
{
break;
}
}
}
cout<<ans;
}
/*
 *||||

 */