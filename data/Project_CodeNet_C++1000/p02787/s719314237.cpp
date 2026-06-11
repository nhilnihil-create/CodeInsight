#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int h, n;
    cin >> h >> n;
    int a[n], b[n];
    rep(i, n) cin >> a[i] >> b[i];

    vector<int> dp(h + 5, INF);
    for (int i = 1; i <= h; i++) {
        rep(j, n) {
            int hp = i - a[j];
            if (hp <= 0)
                dp[i] = min(dp[i], b[j]);
            else
                dp[i] = min(dp[i], dp[hp] + b[j]);
        }
    }

    cout << dp[h] << endl;
    return 0;
}
