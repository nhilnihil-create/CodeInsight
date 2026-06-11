#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    int X[N][D];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> X[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int norm = 0;
            for (int k = 0; k < D; k++) {
                int diff = abs(X[i][k] - X[j][k]);
                norm = norm + diff * diff;
            }
            for (int l = 0; l <= norm; l++) {
                if (l * l == norm) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
