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
int a[N];
int c[N];
int dp[1010][(1<<12)+5];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<(1<<n); j++)
        {
            dp[i][j]=1e9;
        }
    }
    for(int i=1; i<=m; i++)
    {
        int x;
        cin>>a[i]>>x;
        int temp=0;
        for(int j=1; j<=x; j++)
        {
            int y;
            cin>>y;
            y=1<<(y-1);
            temp|=y;
        }
        c[i]=temp;
    }
    dp[0][0]=0;
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<(1<<n); j++)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            int k=j|c[i];
            dp[i][k]=min(dp[i][k],dp[i-1][j]+a[i]);
        }
    }
    if(dp[m][(1<<n)-1]==1e9)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<dp[m][(1<<n)-1]<<endl;
    }
    return 0;
}
