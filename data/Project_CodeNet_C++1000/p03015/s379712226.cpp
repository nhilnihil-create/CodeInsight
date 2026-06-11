#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007LL;

int main() {
    string l;
    cin>>l;
    int n=l.size();
    vector<vector<ll>> dp(n,vector<ll>(2,0LL));
    dp[0][1]=1;
    dp[0][0]=2;
    for(int i = 1; i < n; ++i){
        dp[i][0]=dp[i-1][0]*(l[i]=='0'?1:2);
        dp[i][0]%=mod;
        if(l[i]=='1') {
            dp[i][1]=dp[i-1][0]+dp[i-1][1]*3;
            dp[i][1]%=mod;
        }
        else {
            dp[i][1]+=dp[i-1][1]*3;
            dp[i][1]%=mod;
        }
    }
    cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
    return 0;
}