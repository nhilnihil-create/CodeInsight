#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#define ll long long int
#define hell 1000000007LL
using namespace std;
ll power(ll x, ll y){ 
    if(y==0)
     return 1;
    else
    {
        ll p=power(x,y/2);
        if(y%2==0)
         return (p*p)%hell;
        else
        return (x*((p*p)%hell))%hell;
    }}
ll gcd(ll x,ll y)
{
    if(y==0)
     return x;
    else
    return gcd(y,x%y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    ll x,y;
    ll f[2000000+1];
    f[0]=1;
    f[1]=1;
    for(ll i=2;i<=2000000;i++)
    {
        f[i]=(f[i-1]*i)%hell;
    }
    cin>>x>>y;
    ll a=2*x-y,b=2*y-x;
    if(a>=0&&b>=0&&a%3==0&&b%3==0)
    {
        a=a/3;
        b=b/3;
        ll z=(f[a+b]*power(f[a],hell-2))%hell;
        z=(z*power(f[b],hell-2))%hell;
        cout<<z;
    }
    else
    {
        cout<<0;
    }}