#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int h[n+2];
    h[0] = h[n+1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    long long dp[n+2][k+1];
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = i == 0 ? 0 : 4e11;
            for (int x = 0; x <= j && x <= i - 1; x++) {
                dp[i][j] = min(dp[i][j], dp[i-x-1][j-x] + max(h[i] - h[i-x-1], 0));
            }
        }
    }

    cout << dp[n+1][k] << endl;

    return 0;
}
