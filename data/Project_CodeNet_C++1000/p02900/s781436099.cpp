#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
bool pr(ll n)
{
for(ll i=3;i<=sqrt(n);i+=2)
{
if(n%i==0)
{
return 0;
}
}
return 1;
}
int main()
{
ll a,b;
cin>>a>>b;
ll g=__gcd(a,b);
ll ans=0;
ll j=g;
for(ll i=2;i<=sqrt(g);i+=2)
{
bool ok=0;
while(j%i==0)
{
j/=i;
ok=1;
}
ans+=ok;
if(i==2)
{
i--;
}
}
cout<<ans+1+(j!=1)<<endl;
}