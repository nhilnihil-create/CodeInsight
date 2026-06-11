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
ll m,n;
const int N=1e6+10;
struct A
{
    int x,v;
}f[N];
int cmp(A a,A b)
{
    return a.x<b.x;
}
ll sum[N];
int main()
{
    int a;
    cin>>n>>m>>a;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i].x>>f[i].v;
    }
    sort(f+1,f+1+n,cmp);
    ll ans=0;
    ll now=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]+=sum[i-1];
        f[i].v+=sum[i];
        if(f[i].v<=0)
        {
            continue;
        }
        int l=1,r=n,res=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(f[mid].x<=f[i].x+2*m)
            {
                res=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        int t=f[i].v/a;
        if(f[i].v%a)
        {
            t++;
        }
        ans+=t;
        sum[i]-=t*a;
        sum[res+1]+=t*a;
    }
    cout<<ans<<endl;
    return 0;
}
