#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int H, W;
string S[2000];
int L[2000][2000];
int R[2000][2000];
int D[2000][2000];
int U[2000][2000];

void solve() {
    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c = S[i][j];
            if (c == '#') {
                L[i][j] = 0;
                U[i][j] = 0;
                continue;
            }
            if (j == 0) {
                L[i][j] = 1;
            } else {
                L[i][j] = L[i][j - 1]+1;
            }
            if (i == 0) {
                U[i][j] = 1;
            } else {
                U[i][j] = U[i-1][j] + 1;
            }
        }
    }
    for (int i = H - 1; i >= 0; --i) {
        for (int j = W - 1; j >= 0; --j) {
            char c = S[i][j];
            if (c == '#') {
                R[i][j] = 0;
                D[i][j] = 0;
                continue;
            }
            if (j == W - 1) {
                R[i][j] = 1;
            } else {
                R[i][j] = R[i][j + 1]+1;
            }
            if (i == H - 1) {
                D[i][j] = 1;
            } else {
                D[i][j] = D[i + 1][j] + 1;
            }
        }
    }
    int ans  = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int m = L[i][j]  + R[i][j] + D[i][j] + U[i][j] - 3;
            if (ans < m) ans = m;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}

