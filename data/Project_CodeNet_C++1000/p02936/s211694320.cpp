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
struct A
{
    ll to,next,w;
} a[2*N];
ll head[2*N];
ll res[2*N];
ll r[2*N];
ll vis[2*N];
ll n,m;
ll tot;
void add(int u,int v)
{
    tot++;
    a[tot].to=v;
    a[tot].next=head[u];
    head[u]=tot;
}
void bfs()
{
    queue<ll> q;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=1;
        for(int i=head[x];i!=-1; i=a[i].next)
        {
            ll y=a[i].to;
            if(!vis[y])
            {
                res[y]+=res[x];
                q.push(y);
            }
        }
    }
}
int main()
{
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        res[a]+=b;
    }
    bfs();
    for(int i=1;i<=n;i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}
