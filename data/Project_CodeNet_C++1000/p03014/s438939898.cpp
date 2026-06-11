#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> field(h);
    for (int i = 0; i < h; i++) cin >> field[i];
    vector<vector<int>> line(h, vector<int>(w)), row(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        int cnt = 0;
        for (int j = 0; j < w; j++) {
            if (field[i][j] == '#') {
                cnt = 0;
                continue;
            }
            cnt++;
            line[i][j] = cnt;
        }
        cnt = 0;
        for (int j = w - 1; j >= 0; j--) {
            if (field[i][j] == '#') {
                cnt = 0;
                continue;
            }
            if (cnt == 0) cnt = line[i][j];
            line[i][j] = cnt;
        }
    }
    for (int j = 0; j < w; j++) {
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            if (field[i][j] == '#') {
                cnt = 0;
                continue;
            }
            cnt++;
            row[i][j] = cnt;
        }
        cnt = 0;
        for (int i = h - 1; i >= 0; i--) {
            if (field[i][j] == '#') {
                cnt = 0;
                continue;
            }
            if (cnt == 0) cnt = row[i][j];
            row[i][j] = cnt;
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (field[i][j] == '.') ans = max(ans, row[i][j] + line[i][j] - 1);
        }
    }
    cout << ans << endl;
    return 0;
}