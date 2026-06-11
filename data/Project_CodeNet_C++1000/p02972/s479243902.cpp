#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N + 1);
    vector<bool> C(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];

    int ans = 0;
    for (int i = N; i >= 1; --i) {
        // iの倍数の個数の偶奇
        bool odd = A[i] == 1;
        for (int j = 2; i * j <= N; ++j)
            if (C[i * j]) odd = !odd;
        C[i] = odd;
        if (odd) ans += 1;
    }

    cout << ans << endl;
    if (ans) {
        for (int i = 1; i <= N; ++i)
            if (C[i]) cout << i << ' ';
        cout << endl;
    }
}