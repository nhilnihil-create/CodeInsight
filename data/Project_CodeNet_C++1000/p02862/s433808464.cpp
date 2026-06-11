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
const int mod=1e9+7;
const int N=1e6+10;
ll dp[3][N];
ll power(ll a,ll b)
{
    return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;
}
ll C(ll n,ll k)
{
    ll x=1,y=1;
    for(ll i=1; i<=k; i++)
    {
        x=x*(n-i+1)%mod;
        y=y*i%mod;
    }
    return x*power(y,mod-2)%mod;
}
int main()
{
    ll x,y;
    cin>>x>>y;
    if((x+y)%3!=0)
    {
        printf("0");
        exit(0);
    }
    if(2*x-y>=0)
    {
        printf("%lld\n",C((x+y)/3,(2*x-y)/3));
    }
    else if(2*y-x>=0)
    {
        printf("%lld\n",C((x+y)/3,(2*y-x)/3));
    }
    return 0;
}
