typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    std::cin >> s;
    ll n = s.length();
    
    // i番目までみて、2個使っているかどうか(0,1)
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    
    for (int i = 0; i < n; i++) {
        if(i==0){
            dp[i+1][1] = 0;
            dp[i+1][0] = 1;
            continue;
        }
        
        if(s[i]!=s[i-1]) dp[i+1][0] = max(dp[i+1][0],dp[i][0]+1);
        dp[i+1][0] = max(dp[i+1][0],dp[i][1]+1);
        
        if(i>=3)if(s.substr(i-1,2)!=s.substr(i-3,2)) dp[i+1][1] = max(dp[i+1][1],dp[i-1][1]+1);
        dp[i+1][1] = max(dp[i+1][1],dp[i-1][0]+1);
    }
    
    std::cout << max(dp[n][0], dp[n][1]) << std::endl;
}
