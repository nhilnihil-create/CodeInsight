#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;

int dp[2005];

int main()
{
    int n;
    cin>>n;
    dp[0] = 1;
    for(int i=3;i<=n;i++) {
        for(int j=3;j<=i;j++) {
            dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }
    cout<<dp[n]<<endl;

    return 0;
}
