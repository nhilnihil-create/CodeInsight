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
ll m,n,p;
ll zero[1010];
ll one[1010];
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
        n=n>>1;
    }
    return ans;
}

int main()
{
    cin>>n;
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        for(int k=64; k>=1; k--)
        {
            if(x&(1ll<<(k-1)))
            {
                ans+=zero[k]*pows(2,k-1);
                one[k]++;
                ans%=mod;
            }
            else
            {
                ans+=one[k]*pows(2,k-1);
                zero[k]++;
                ans%=mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
