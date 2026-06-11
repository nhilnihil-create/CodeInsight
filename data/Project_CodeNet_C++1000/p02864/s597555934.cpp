#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[500][500];

const ll LINF = 1e18+5;

int main() {
    int n,k;
    cin >> n >> k;
    int h[500] = {};
    for (int i=1;i<=n;i++) cin >> h[i];

    for (int i=0;i<=n;i++)
        for (int j=0;j<=i;j++)
            dp[i][j] = LINF; // impossible
    
    dp[0][0] = 0;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            for (int x=j-1;x<i;x++) {
                dp[i][j] = min(dp[i][j],dp[x][j-1]+max(0,h[i]-h[x]));
            }
        }
    }

    ll ans = LINF;
    for (int i=n-k;i<=n;i++) {
        ans = min(dp[i][n-k],ans);
    }
    cout << ans << endl;
    return 0;
}