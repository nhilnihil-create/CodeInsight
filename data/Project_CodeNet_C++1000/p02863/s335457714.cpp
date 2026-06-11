typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,t;
    std::cin >> n>>t;
    vector<pair<ll,ll>> ab(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(),ab.end());
    vector<vector<ll>> dp(n+1,vector<ll>(t,0));
    vector<ll> ma(n,0);

    ma[n-1] = ab[n-1].second;
    for (int i = 1; i < n; i++) {
        ma[n-1-i] = max(ab[n-1-i].second, ma[n-1-i+1]);
    }
    ll ans = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < t; j++) {
            dp[i+1][j] = dp[i][j];
            if(j-ab[i].first>=0) dp[i+1][j] = max(dp[i+1][j],dp[i][j-ab[i].first]+ab[i].second);
        }
        ans = max(ans, dp[i+1][t-1]+ma[i+1]);
    }
    std::cout << ans << std::endl;
}