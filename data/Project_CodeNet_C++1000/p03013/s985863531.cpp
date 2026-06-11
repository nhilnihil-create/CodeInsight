#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long dp[100100];

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> stairs(N + 1, true);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        stairs[a] = false;
    }

    for (int i = 0; i < 100100; i++) dp[i] = 0;
    dp[0] = 1;
    if (stairs[1]) dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (!stairs[i]) continue;
        dp[i] += (dp[i - 2] + dp[i - 1]) % mod;
        dp[i] %= mod;
    }

    cout << dp[N] << endl;
}