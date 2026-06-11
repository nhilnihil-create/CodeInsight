#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int dp[n][n]; rep(i,n) rep(j,n) dp[i][j] = 0;
    rep(i,n) {
        if (s[i] == s[n-1]) {
            dp[i][n-1] = 1;
            dp[n-1][i] = 1;
        }
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = n-2; j >= 0; j--) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
            }
        }
    }
    //rep(i,n) {rep(j,n) {printf("%d ", dp[i][j]);} printf("\n");}
    int ans = 0;
    rep(i,n) {
        rep(j,i) {
            int c = min(dp[i][j], i-j);
            ans = max(ans,c);
        }
    }
    cout << ans << endl;
    return 0;
}
