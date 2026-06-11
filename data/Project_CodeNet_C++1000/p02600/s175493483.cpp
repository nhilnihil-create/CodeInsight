#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll n,ll p,ll mod)
{
  if(p==0) return 1;
  ll temp=power(n,p/2,mod)%mod;
  temp=(temp*temp)%mod;
  if(p%2 !=0) temp*=n;
  return temp%mod;
}

int main()
{
    ll n;cin>>n;
    if(n>=400 && n<600) cout<<8;
    else if(n>=600 && n<800) cout<<7;
    else if(n>=800 && n<1000) cout<<6;
    else if(n>=1000 && n<1200) cout<<5;
    else if(n>=1200 && n<1400) cout<<4;
    else if(n>=1400 && n<1600) cout<<3;
    else if(n>=1600 && n<1800) cout<<2;
    else if(n>=1800 && n<2000) cout<<1;
    
}