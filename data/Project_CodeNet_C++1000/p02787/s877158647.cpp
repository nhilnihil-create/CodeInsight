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
const int N = 1e3 + 5;
const int M = 2e4 + 5;
int n,m;
ll dp[N][M];
int  a[8500],b[5000];
int main()
{
    cin>>n>>m;
    memset(dp,inf,sizeof(dp));
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
    }
    dp[0][0]=0;
    for(ll i=1;i<=m;i++)
    {
        for(int  j=0;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j];
            dp[i][j]=min(dp[i][j],dp[i][max(0,j-a[i])]+b[i]);
        }
    }
    cout<<dp[m][n]<<endl;
    return 0;
}
