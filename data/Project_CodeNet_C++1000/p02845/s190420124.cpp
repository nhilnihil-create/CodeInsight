#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    ll ans = 1;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<vector<int>> dp(N+1, vector<int>(3, 0));
    rep(i, N) {
        ll cnt  = 0;
        int fst = 99;
        if (dp[i][0] == A[i]) {
            cnt++;
            fst = min(fst, 0);
        }
        if (dp[i][1] == A[i]) {
            cnt++;
            fst = min(fst, 1);
        }
        if (dp[i][2] == A[i]) {
            cnt++;
            fst = min(fst, 2);
        }

        if (cnt == 0) {
            cout << 0 << endl;
            return 0;
        }
        ans *= cnt;
        ans %= MOD;
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
        dp[i + 1][2] = dp[i][2];
        dp[i + 1][fst]++;
    }

    cout << ans << endl;
}