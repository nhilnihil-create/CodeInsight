#include <bits/stdc++.h>

using namespace std;
using lint = long long;
const auto MOD = (long long) 1e9 + 7;

int main() {
    lint N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(), B.end());

    lint ans = 0;
    lint cnt1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) cnt1++;
        }
    }
    ans += cnt1 * K % MOD;

    lint cnt2 = 0;
    lint t = K * (K - 1) / 2 % MOD;
    for (int i = 0; i < N; i++) {
        cnt2 += lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        cnt2 %= MOD;
    }
    ans += cnt2 * t % MOD;
    ans %= MOD;

    cout << ans << endl;
    return 0;
}
