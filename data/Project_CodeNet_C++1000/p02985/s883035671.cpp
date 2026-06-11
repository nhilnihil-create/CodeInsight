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
const int mod=1e9+7;
vector <int> g[N];
int n,k;
ll ans;
ll bfs(int u,int fa,int dep)
{
    int tem=k-min(dep,2);
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==fa)
            continue;
        if(bfs(v,u,dep+1)==0)
            return 0;
        ans=ans*tem%mod;
        tem--;
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ans=k;
    printf("%lld\n",bfs(1,-1,1));
    return 0;
}
