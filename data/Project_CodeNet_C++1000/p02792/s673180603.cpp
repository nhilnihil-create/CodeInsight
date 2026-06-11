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
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
int dp[11][11];

int main()
{
    string a;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        a=to_string(i);
        dp[a[0]-'0'][a.back()-'0']++;
    }
    ll ans=0;
    for(int i=0; i<=9; ++i)
        for(int j=0; j<=9; ++j)
            ans+=dp[i][j]*dp[j][i];
    cout<<ans;
    return 0;
}
