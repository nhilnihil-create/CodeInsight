#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n,t;
    cin>>n>>t;
    vector<pair<int,int>> d;
    for(int i = 0;i < n;++i) {
        int a,b;
        cin>>a>>b;
        d.emplace_back(a,-b);
    }
    sort(d.begin(),d.end());
    vector<vector<int>> dp(n,vector<int>(t+1,0));
    for(int i = 0;i < t;++i) {
        dp[0][min(t,i+d[0].first)]=-d[0].second;
    }
    for(int i = 1;i < n;++i) {
        int a=d[i].first;
        int b=-d[i].second;
        for(int j = 0;j < t;++j) {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            int nt=j+a;
            nt=min(nt,t);
            dp[i][nt]=max(max(dp[i][nt],dp[i-1][nt]),dp[i-1][j]+b);
        }
    }
    int ans=0;
    for(int i = 0;i < t+1;++i) {
        ans=max(ans,dp[n-1][i]);
    }
    cout<<ans<<endl;
    return 0;
}
