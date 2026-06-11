#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
ll fac[5500];
ll pows(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        n>>=1;
    }
    return ans%mod;
}
ll inv(ll a)
{
    return pows(a,mod-2)%mod;
}
ll c(ll n,ll m)
{
    if(n==0||m==n)
		return 1;
	if(m<n)
		return 0;
    return fac[m]*inv(fac[m-n])%mod*inv(fac[n])%mod;
}
int main()
{
    fac[0]=1;
    for(ll i=1; i<3000; i++)
    {
        fac[i]=fac[i-1]*i%mod;
    }
    ll n,k;
    ll ans;
    cin>>n>>k;
    for(ll i=1; i<=k; i++)
    {
        ll a,b;
        a=c(i,n-k+1);
        b=c(i-1,k-1);
        ans=a*b%mod;
        cout<<ans<<endl;
    }
    return 0;
}
