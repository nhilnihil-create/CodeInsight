#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const ll MOD = 998244353;
ll dp[3005][3005] = {};

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    dp[0][0] = 1LL;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k <= S; ++k) {
            if (A[i] <= k)
                dp[i + 1][k] = (2 * dp[i][k] + dp[i][k - A[i]]) % MOD;
            else
                dp[i + 1][k] = 2 * dp[i][k] % MOD;
        }
    }

    cout << dp[N][S] << endl;
}