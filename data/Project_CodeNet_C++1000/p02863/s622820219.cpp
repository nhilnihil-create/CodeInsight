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
struct A
{
    int  w,v;
} a[3050];
bool cmp(A a,A b)
{
    return a.w<b.w;
}
ll dp[3500][6050];
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].w>>a[i].v;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<a[i].w+m; j++)
        {
            if(j>=a[i].w)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].w]+a[i].v);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    ll res=0;
    for(int i=1; i<=n; i++)
        res=max(dp[n][m+a[i].w-1],res);
    cout<<res<<endl;
    return 0;
}
