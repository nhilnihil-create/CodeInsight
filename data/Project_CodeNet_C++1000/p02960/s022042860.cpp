#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
ll dp[100005][13];
string S;

void solve() {
    cin >> S;
    int N = S.size();

    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        int c = S[i] == '?' ? -1 : S[i] - '0';
        for (int j = 0; j < 10; ++j) {
            if (c != -1 && c != j) continue;
            for (int k = 0; k < 13; ++k) {
                dp[i+1][(k*10 + j) % 13] += dp[i][k];
            }
            for (int j = 0; j < 13; ++j) {
                dp[i+1][j] %= MOD;
            }
        }
    }

    cout << dp[N][5] << endl;
}

int main() {
    solve();
    return 0;
}
