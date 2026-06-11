#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<int>> cntV(H, vector<int>(W)), cntH(H, vector<int>(W));
    for (int y = 0; y < H; y++) {
        int cnt = 0;
        int l = 0;
        for (int x = 0; x <= W; x++) {
            if (x == W || S[y][x] == '#') {
                for (int k = l; k < x; k++) {
                    cntH[y][k] = cnt;
                }
                cnt = 0;
                l = x + 1;
            } else {
                cnt++;
            }
        }
    }
    for (int x = 0; x < W; x++) {
        int cnt = 0;
        int t = 0;
        for (int y = 0; y <= H; y++) {
            if (y == H || S[y][x] == '#') {
                for (int k = t; k < y; k++) {
                    cntV[k][x] = cnt;
                }
                cnt = 0;
                t = y + 1;
            } else {
                cnt++;
            }
        }
    }
    int ans = INT_MIN;
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            ans = max(ans, cntV[y][x] + cntH[y][x] - 1);
        }
    }
    cout << ans << endl;
    return 0;
}
