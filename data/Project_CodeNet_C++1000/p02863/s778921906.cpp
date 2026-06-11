#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[3005][6005];

int main() {
    int n, t;
    cin >> n >> t;
    vector<P> A(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        A[i] = P(a, b);
    }
    sort(A.begin(), A.end());
    rep(i, n) rep(j, t) {
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        dp[i+1][j+A[i].first] = max(dp[i][j+A[i].first], dp[i][j]+A[i].second); 
    }
    int ans = 0;
    rep(i, n+1) rep(j, 6005){
        ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
    return 0;
}