/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
 * ABC147 F
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll n;
cin>>n;
if(n%2==1)
{
cout<<0<<endl;
}
else
{
ll ans=0;
for(ll i=10;i<=n;i*=5)
{
ans+=n/i;
}
cout<<ans<<endl;
}
}