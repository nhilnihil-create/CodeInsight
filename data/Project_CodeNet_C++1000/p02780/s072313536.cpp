#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<double> p(N);
    for (int i = 0; i < N; i++) {
        double tmp;
        cin >> tmp;
        p[i] = (tmp + 1) / 2;
    }

    vector<double> dp(N);
    for (int i = 0; i < K; i++) {
        dp[0] += p[i];
    }
    for (int i = 1; i < N - K + 1; i++) {
        dp[i] = dp[i - 1] - p[i - 1] + p[i + K - 1];
    }

    sort(dp.begin(), dp.end());
    printf("%f\n", dp[dp.size() - 1]);

    return 0;
}
