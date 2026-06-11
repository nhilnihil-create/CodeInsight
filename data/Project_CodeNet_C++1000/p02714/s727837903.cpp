#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    int x, y;
    long long ans, dp[4002][3] = {};
    string s;
    char cat[] = "RGB";

    cin >> n >> s;
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            if ( cat[j] == s[i] ) {
                dp[i+1][j]++;
            }
            dp[i+1][j] += dp[i][j];
        }
    }

    ans = 0;
    for ( int i = 0; i < n; i++ ) {
        for (int j = 0; j < 3; j++ ) {
            if ( cat[j] == s[i] ) {
                ans += (dp[n][ (j+1)%3 ] - dp[i+1][ (j+1)%3 ]) * dp[i][ (j+2)%3 ];
                ans += (dp[n][ (j+2)%3 ] - dp[i+1][ (j+2)%3 ]) * dp[i][ (j+1)%3 ];
            }
        }

        x = y = i;
        while ( x >= 0 && y <= n-1 ) {
            if ( s[x] != s[y] && s[x] != s[i] && s[y] != s[i] ) {
                ans -= 1;
            }

            x--;
            y++;
        }
    }

    cout << ans << endl;

    return (0);
}