#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N, K;
    cin >> N >> K;

    if (K <= (N - 1) * (N - 2) / 2) {
        K = (N - 1) * (N - 2) / 2 - K;

        cout << K + N - 1 << "\n";
        rep(i, N - 1) cout << 1 << " " << i + 2 << "\n";

        for (int i = 2; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (K != 0) {
                    cout << i << " " << j << "\n";
                    --K;
                }
            }
        }
    } else {
        cout << -1 << "\n";
    }

    return 0;
}