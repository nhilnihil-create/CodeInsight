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
const int N=1e5+10;
const int mod=1e9+7;
ll a[N],b[N];
ll cmp(ll a,ll b)
{
    return a>b;
}
ll n,m,v,p;
bool judge(ll mid)
{
    if(mid<=p)
    {
        return 1;
    }
    if(a[mid]+m<a[p])
    {
        return 0;
    }
    if(v<=p-1&&a[mid]+m>=a[p])
        return true;
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i];
    }
    ll temp=0;
    for(int i=1;i<p;i++)
    {
        b[i]+=m;
        temp+=m;
    }
    ll inx=n,cnt=v-p+1;
    while(inx>mid&&cnt>1)
    {
        temp+=m;
        inx--;
        cnt--;
        b[inx]+=m;
    }
    temp+=m;
    ll now=a[mid]+m;
    ll res=m*v-temp;
    //中间还能被填多少
    for(int i=p;i<mid;i++){
        ll add=min(m,max(now-a[i],0ll));
        if(add>res)add=res;
        res-=add;
        b[i]+=add;
    }
    return now>=b[p]&&res<=0;
}
int main()
{
    cin>>n>>m>>v>>p;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int l=1,r=n;
    ll ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(judge(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
