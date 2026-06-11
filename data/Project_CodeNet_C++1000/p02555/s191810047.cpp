#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define mod 1000000007

int main()
{
    int s; cin >> s;
    vector<int> dp(s+1, 0);
    dp[0] = 1;
    for(int i=1; i<=s; i++){
        for(int j=0; j<=i-3; j++){
            dp[i] += dp[j];
            dp[i] %= mod;
        }
            
    }

    cout << dp[s] << endl;
    return 0;
    
}