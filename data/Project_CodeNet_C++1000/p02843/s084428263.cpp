#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int x;
    cin>>x;
    bool * dp = new bool[x+1]();
    dp[0] = true;
    for(int i=100;i<=x;i++)
    {
        if( i-100 >=0 )
            dp[i ] = dp[i ] || dp[i-100];
        if( i-101 >=0 )
            dp[i ] = dp[i ] || dp[i-101];
        if( i-102 >=0 )
            dp[i ] = dp[i ] || dp[i-102];
        if( i-103 >=0 )
            dp[i ] = dp[i ] || dp[i-103];
        if( i-104 >=0 )
            dp[i ] = dp[i ] || dp[i-104];
        if( i-105 >=0 )
            dp[i ] = dp[i ] || dp[i-105];
    }
    if( dp[x] )
        cout<<1;
    else cout<<0;
}