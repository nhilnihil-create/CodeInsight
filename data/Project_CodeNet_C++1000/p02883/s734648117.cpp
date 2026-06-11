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
const int N=2e5+10;
ll a[N],b[N];
ll sum;
ll n,k;
bool check(ll x,ll k)
{
    for(int i = 1 , j = n ; i <= n ; i++ , j--)
    {
        ll temp=a[i]*b[j];
        if(temp>x)
        {
            k -= (temp - x) / b[j];
            if((temp - x) % b[j] != 0)
                k--;
        }
        if(k<0)
        {
            break;
        }
    }
    if(k >= 0)
        return true;
    else
        return false;
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    if(sum-k<=0)
    {
        cout<<0<<endl;
        return 0;
    }
    ll l=0,r=a[n]*b[n],ans=0;
    while(l<=r)
    {
        ll mid= (l + r + 1LL)>>1;
        if(check(mid,k))
        {
            r=mid-1;
            ans=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
