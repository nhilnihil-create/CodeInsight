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
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
const int mod=998244353;
int n,s;
int a[200020];
ll dp[3030][3030];
int main()
{
    cin>>n>>s;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    dp[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            dp[i][j]=(dp[i-1][j]*2)%mod;
            if(j>=a[i])
                dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
        }
    }
    cout<<dp[n][s];
    return 0;
}
