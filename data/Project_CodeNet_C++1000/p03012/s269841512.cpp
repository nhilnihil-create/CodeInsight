#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W[110];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> W[i];

    int sum[N + 1] = {};
    for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + W[i - 1];

    int ans = 1001001;
    for (int i = 1; i < N; i++) {
        int S1 = sum[i];
        int S2 = sum[N] - sum[i];
        ans = min(ans, abs(S1 - S2));
    }

    cout << ans << endl;
}