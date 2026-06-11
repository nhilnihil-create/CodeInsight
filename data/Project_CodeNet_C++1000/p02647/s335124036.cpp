#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=200005;
int t[4*maxn];
void build(int node,int tl,int tr)
{
    t[node]=0;
    if((tr-tl)==1)
    {
        return;
    }
    int tm=(tl+tr)>>1;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
}
void pl(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        t[node]++;
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    int tm=(tl+tr)>>1;
    pl(2*node+1,tl,tm,l,r);pl(2*node+2,tm,tr,l,r);
}
int get(int node,int tl,int tr,int pos)
{
    if(tl>pos || tr<=pos)
    {
        return 0;
    }
    if((tr-tl)==1)
    {
        return t[node];
    }
    int tm=(tl+tr)>>1;
    return t[node]+get(2*node+1,tl,tm,pos)+get(2*node+2,tm,tr,pos);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int cyc=0;cyc<min(50LL,k);++cyc)
    {
        build(0,0,maxn);
        for(int i=0;i<n;++i)
        {
            int x=a[i];
            pl(0,0,maxn,max(0LL,i-x),min(n,i+x+1));
        }
        for(int i=0;i<n;++i)
        {
            a[i]=get(0,0,maxn,i);
        }
    }
    for(int i=0;i<n;++i) cout<<a[i]<<' ';
    return 0;
}
