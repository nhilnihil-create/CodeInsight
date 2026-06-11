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
#define inf 0x3f3f3f3f3f3f3f3f
#define pi 3.1415926535898
#define N 200010
using namespace std;
struct A
{
    int x;
    int y;
}a[N];
char s[110][110];
int dp[110][110];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }
    memset(dp,inf,sizeof(dp));
    dp[1][1]=(s[1][1]=='#');
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j+1]=='.')
            {
                dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
            }
            else
            {
                dp[i][j+1]=min(dp[i][j+1],dp[i][j]+(s[i][j]=='.'));
            }
            if(s[i+1][j]=='.')
            {
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            }
            else
            {
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(s[i][j]=='.'));
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
