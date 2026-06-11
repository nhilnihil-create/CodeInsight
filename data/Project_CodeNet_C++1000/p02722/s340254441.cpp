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
#define inf 0x3f3f3f3f3f3f3f3f
#define pi 3.1415926535898
#define mod 998244353
#define N 200010
using namespace std;
ll n;
int check(ll x)
{
    ll t=n;
    while(t%x==0)
    {
        t=t/x;
    }
    t=t%x;
    if(t==1)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    cin>>n;
    if(n==2)
    {
        cout<<1<<endl;
    }
    else
    {
        ll res=2,t=n-1;
        for(ll i=2; i*i<=t; i++)
        {
            if(t%i==0)
            {
                res++;
                if(i*i!=t)
                {
                    res++;
                }
            }
        }
        for(ll i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                res=res+check(i);
                if(i*i!=n)
                {
                    res=res+check(n/i);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
