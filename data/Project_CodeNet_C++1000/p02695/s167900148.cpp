#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
using namespace std;
int p[55];
int a[55],b[55],c[55],d[55];
int sum=-inf;
int n,m,q;
void choc()
{
    int x=0;
    for(int i=0; i<q; i++)
    {
        if(p[b[i]]-p[a[i]]==c[i])
        {
            x+=d[i];
        }
    }
    sum=max(sum,x);
    return ;
}
void dfs(int now,int s)
{
    p[now]=s;
    if(now==n)
    {
        choc();
        return ;
    }
    for(int i=s;i<=m; i++)
    {
        dfs(now+1,i);
    }
}
int main()
{
    cin>>n>>m>>q;
    for(int i=0; i<q; i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    dfs(1,1);
    cout<<sum<<endl;
    return 0;
}
