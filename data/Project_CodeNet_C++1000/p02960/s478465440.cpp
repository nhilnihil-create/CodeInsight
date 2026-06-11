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
char s[N];
int dp[100050][13];
int main()
{
    cin>>(s+1);
    int n=strlen(s+1);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='?')
        {
            for(int k=0;k<10;k++)
            {
                for(int j=0;j<13;j++)
                {
                    dp[i][(j*10+k)%13]=(dp[i][(j*10+k)%13]+dp[i-1][j])%mod;
                }
            }
        }
        else
        {
            int k=s[i]-'0';
            for(int j=0;j<13;j++)
            {
                dp[i][(j*10+k)%13]=(dp[i][(j*10+k)%13]+dp[i-1][j])%mod;
            }
        }
    }
    cout<<dp[n][5];
    return 0;
}
