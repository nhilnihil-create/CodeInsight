/*
h s, d't skp th si tll i's sved
 * ABC141 E
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll n;
cin>>n;
ll ans=n-1;
for(ll i=2;i<=sqrt(n);i++)
{
if(n%i==0)
{
ans=min(ans,i-1+n/i-1);
}
}
cout<<ans;
}