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
const int N=1e6+10;
ll n,m;
char str[N];
ll dp[N],p[N];
ll pre[N];
void ps(int x)
{
    if(pre[x]==-1)
    {
        cout<<x;
        return ;
    }
    ps(pre[x]);
    cout<<" "<<x-pre[x];
}
int main()
{
    memset(pre,-1,sizeof(pre));
    cin>>n>>m;
    cin>>str;
    int s=1,e=0;
    for(int i=0; i<=m; i++)
    {
        if(str[i]=='0')
            dp[i]=1;
        else
        {
            dp[i]=inf;
        }
        while(s<=e&&dp[i]<dp[p[e]])
            e--;
        p[++e]=i;
    }
    s++;
    for(int i=m+1; i<=n; i++)
    {
        dp[i]=inf;
        if(str[i]=='0')
        {
            dp[i]=min(dp[p[s]]+1,dp[i]);
            if(!dp[i]!=inf)
                pre[i]=p[s];
        }
        while(s<=e&&dp[i]<dp[p[e]])
            e--;
        p[++e]=i;
        while(s<=e&&p[s]<i+1-m)
            s++;
    }
    if(dp[n]==inf)
        cout<<-1<<endl;
    else
        ps(n);
    return 0;
}
