#include<bits/stdc++.h>
using namespace std;
#define int     long long
#define F       first
#define S       second
#define _READ   freopen("input.txt","r", stdin);
#define _FAST   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
void solve()
{
    int n,s;
    const int mod=998244353;
    cin>>n>>s;
    vector<int> ar(n+1);
    for(int i=1;i<=n;i++)
        cin>>ar[i];
    vector<vector<int>> dp(n+1,vector<int>(s+1,0));
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            //  00 and 01 case
            if(i>=1)
                dp[i][j]+=dp[i-1][j]*2;
            dp[i][j]%=mod;
            //11 case 
            if(i>=1 && j-ar[i]>=0)
                dp[i][j]+=dp[i-1][j-ar[i]];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][s];
}
int32_t main()
{
    solve();
    return 0;
}
/*
===FOR N-Dimensional Vector===
https://codeforces.com/blog/entry/76149
g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined a.cpp -o a -D_GLIBCXX_DEBUG
*/
