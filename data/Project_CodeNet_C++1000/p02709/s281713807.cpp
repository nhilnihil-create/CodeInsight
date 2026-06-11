#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    pii ai[n];
    for (int i = 0; i < n; i++) {
        cin >> ai[i].first;
        ai[i].second = i;
    }
    sort(ai, ai+n);

    ll dp[n][n];
    fill(dp[0], dp[n], 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i < n - 1) {
                dp[i][j] = max(dp[i][j], dp[i+1][j] + 1ll * ai[j-i].first * abs(ai[j-i].second - i));
            }
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j-1] + 1ll * ai[j-i].first * abs(ai[j-i].second - j));
            }
        }
    }

    cout << dp[0][n-1] << endl;

    return 0;
}
