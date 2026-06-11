#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
    }

    int div = 1000000007;
    vector<ll> dp(N, 0);

    if (find(a.begin(), a.end(), 1) == a.end()) {
        dp[0] = 1;
    }
    if (find(a.begin(), a.end(), 2) == a.end()) {
        dp[1] = dp[0] + 1;
    }

    for (int i = 2; i < N; i++) {
        if (find(a.begin(), a.end(), i + 1) == a.end()) {
            dp[i] = (dp[i - 1] % div) + (dp[i - 2] % div);
            dp[i] = dp[i] % div;
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}
