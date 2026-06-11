#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;
const ll INF = 10010010010010010;


int main() {
    string s,t; cin >> s >> t;
    int n = s.size(), m = t.size();
    int dp[n][26]; rep(i,n) rep(j,26) dp[i][j] = -1;
    for (int i = n-1; i >= 0; i--) {
        dp[n-1][s[i]-'a'] = i;
    }
    //rep(i,n) {rep(j,26) {printf("%d ", dp[i][j]);} printf("\n");}
    for (int i = n-2; i >= 0; i--) {
        rep(j,26) {
            dp[i][j] = dp[i+1][j];
        }
        dp[i][s[i+1]-'a'] = i+1;
    }
    //rep(i,n) {rep(j,26) {printf("%d ", dp[i][j]);} printf("\n");}
    int idx = -1;
    rep(i,n) {
        if (t[0] == s[i]) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << idx << endl;
        return 0;
    }
    ll ans = 0;
    rep(i,m-1) {
        int nx = dp[idx][t[i+1]-'a'];
        if (nx == -1) {
            cout << -1 << endl;
            return 0;
        }
        else if (nx > idx) {
            idx = nx;
        }
        else {
            idx = nx;
            ans += n;
        }
    }
    ans += idx + 1;
    cout << ans << endl;

    return 0;
}
