#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, t;
    cin >> n >> t;
    vector<P> a(n);
    rep(i, n)cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    vector<vector<int>> dp(n, vector<int>(t, 0));
    rep(i, n-1){
        for(int j = 1; j < t; j++){
            dp[i+1][j] = max(dp[i+1][j-1], dp[i][j]);
            if(j >= a[i].first){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-a[i].first] + a[i].second);
            }
        }
    }
    int ans = 0;
    rep(i, n){
        ans = max(ans, dp[i][t-1] + a[i].second);
    }
    cout << ans << endl;
}