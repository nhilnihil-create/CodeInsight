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
const int mod=998244353;
const int N=1e6+10;
ll pows(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)
        {
            ans=ans*a%mod;;
        }
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    ll maxs=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[0]!=0)
        {
            cout<<0<<endl;
            return 0;
        }
        if(i!=0&&a[i]==0)
        {
            cout<<0<<endl;
            return 0;
        }
        b[a[i]]++;
		maxs = max(maxs,a[i]);
    }
     ll ans=1;
     for(int i=0;i<maxs;i++)
     {
         for(int j=0;j<b[i+1];j++)
         {
             ans=ans*b[i]%mod;
         }
     }
     cout<<ans<<endl;
    return 0;
}
