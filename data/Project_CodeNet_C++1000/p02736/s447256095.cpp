#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 2;

signed main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int a[n];
    bool one = false;
    rep(i, n) {
        a[i] = s[i] - '1';
        if (a[i] == 1) one = true;
    }
    if (!one) {
        rep(i, n) {
            a[i] /= 2;
        }
    }
    int dp[n] = {};
    for (int i = 1; i < n; i++){
        int t = i, cnt = 0;
        while(t % 2 == 0){
            t /= 2;
            cnt++;
        }
        dp[i] = dp[i - 1] + cnt;
    }
    int ans = 0;
    rep(i, n) {
        ans += a[i] * !(dp[n - 1] - dp[i] - dp[n - 1 - i] > 0);
        ans %= 2;
    }
    if (!one) ans *= 2;
    cout << ans << endl;
    return 0;
}