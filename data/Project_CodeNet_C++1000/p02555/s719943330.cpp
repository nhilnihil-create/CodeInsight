#include<bits/stdc++.h>

using namespace std;

int main()
{
    int s;
    cin>>s;
    vector<int> dp(s+1,0);
    int mod = 1e9 + 7;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;
    for(int i = 3;i<=s;i++)
    {
        int j = 3;
        while(j <= i)
        {
            dp[i] = (dp[i] + dp[i-j]) % mod;
            j++;
        }
    }

    cout<<dp[s]<<"\n";

    return 0;
}