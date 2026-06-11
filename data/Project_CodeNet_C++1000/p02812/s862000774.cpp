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
    ll c=0,n;
    string s;
    cin>>n>>s;
    if(n<3)
    cout<<0;
    else{
    for(int i=0;i<n-2;i++)
    {
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')
        c++;
    }
    cout<<c;}}