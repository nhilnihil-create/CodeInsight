#include <bits/stdc++.h>
using namespace std; 

int main() {
    int h, w, k; cin >> h >> w >> k; char grid[h][w]; int ans = 0;
    for (int i = 0; i < h; i ++) for (int j = 0; j < w; j ++) cin >> grid[i][j];
    for (int i = 0; i < (1<<h); i ++) {
        for (int j = 0; j < (1<<w); j ++) {
            char newgrid[h][w]; for (int a = 0; a < h; a ++) for (int b = 0; b < w; b ++) newgrid[a][b] = grid[a][b];
            for (int a = 0; a < h; a ++) {
                if ((1<<a)&i) for (int b = 0; b < w; b ++) newgrid[a][b] = '?';
            } for (int a = 0; a < w; a ++) {
                if ((1<<a)&j) for (int b = 0; b < h; b ++) newgrid[b][a] = '?';
            } int cnt = 0; for (int a = 0; a < h; a ++) for (int b = 0; b < w; b ++) if (newgrid[a][b] == '#') cnt++;
            if (cnt == k) ans++;
        }
    } cout << ans << endl;
}