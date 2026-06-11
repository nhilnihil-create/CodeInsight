#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, X; cin >> N >> M >> X;
    int C[N], A[N][M];
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < M; j++) cin >> A[i][j];
    }
    int ans = INT_MAX;
    for (int bits = 0; bits < (1 << N); bits++) {
        int p[M] = {};
        int money = 0;
        for (int i = 0; i < N; i++) {
            if (bits & (1 << i)) {
                money += C[i];
                for (int j = 0; j < M; j++) {
                    p[j] += A[i][j];
                }
            }
        }
        bool ok = true;
        for (int j = 0; j < M; j++) ok = ok && (p[j] >= X);
        if (ok) ans = min(money, ans);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
}