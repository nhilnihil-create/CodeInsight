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
ll ans=0;
for(ll i=2;i<=sqrt(n);i++)
{
if(n%i==0)
{
ll k=n;
while(k%i==0)
{
k/=i;
}
if((k-1)%i==0)
{
ans++;
}
if(n/i!=i)
{
k=n;
while(k%(n/i)==0)
{
k/=(n/i);
}
if((k-1)%(n/i)==0)
{
ans++;
}
}
}
}
for(ll i=1;i<=sqrt(n-1);i++)
{
if((n-1)%i==0)
{
if(i!=1)
{
ans++;
}
if((n-1)/i!=i)
{
ans++;
}
}
}
cout<<ans+1<<endl;
}



/*
 * ||||


 */