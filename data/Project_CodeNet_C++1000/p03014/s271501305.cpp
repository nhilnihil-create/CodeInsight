#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int H, W;
    int ans = 0;
    cin >> H >> W;
    vector<string>S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    int L[H][W];
    int R[H][W];
    int D[H][W];
    int U[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            L[i][j] = 0;
            R[i][j] = 0;
            D[i][j] = 0;
            U[i][j] = 0;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                L[i][j] = 0;
                D[i][j] = 0;
            } else {
                if (j == 0) {
                    L[i][j] = 1;
                } else {
                    L[i][j] = L[i][j-1] + 1;
                }
                if (i == 0) {
                    D[i][j] = 1;
                } else {
                    D[i][j] = D[i-1][j] + 1;
                }
            }
        }
    }
    for (int i = H-1; i >= 0; i--) {
        for (int j = W-1; j >= 0; j--) {
            if (S[i][j] == '#') {
                R[i][j] = 0;
                U[i][j] = 0;
            } else {
                if (j == W-1) {
                    R[i][j] = 1;
                } else {
                    R[i][j] = R[i][j+1] + 1;
                }
                if (i == H-1) {
                    U[i][j] = 1;
                } else {
                    U[i][j] = U[i+1][j] + 1;
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = max(ans, R[i][j]+L[i][j]+D[i][j]+U[i][j]-3);
        }
    }
    cout << ans << endl;
}
