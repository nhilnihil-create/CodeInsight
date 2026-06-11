#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
int INF = 1001001001;

int main() {
    int n,m; cin >> n >> m;
    int n2 = (1<<n);
    int dp[m+1][n2]; rep(i,m+1) rep(j,n2) dp[i][j] = INF;
    dp[0][0] = 0;
    int a,b,c;
    rep(i,m) {
        cin >> a >> b;
        int score = 0;
        rep(j,b) {
            cin >> c;
            c--;
            c = 1<<c;
            score += c;
        }
        rep(j,n2) dp[i+1][j] = dp[i][j];
        rep(j,n2) {
            int jj = j | score;
            dp[i+1][jj] = min(dp[i][j]+a, dp[i+1][jj]);
        }
    }
    //rep(i,m+1) {rep(j,n2) printf("%d ", dp[i][j]);printf("\n");}
    if (dp[m][n2-1] == INF) cout << -1 << endl;
    else cout << dp[m][n2-1] << endl;
    return 0;
}
