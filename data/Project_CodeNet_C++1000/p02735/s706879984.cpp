#include <bits/stdc++.h>

#include <deque>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
using coord = pair<int, int>;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i = 0; i < H; i++) {
        cin >> s[i];
    }

    vector<vector<int>> dp(H, vector<int>(W, -1));
    if (s[0][0] == '.') {
        dp[0][0] = 0;
    } else {
        dp[0][0] = 1;
    }
    for (int w = 1; w < W; w++) {
        if (s[0][w - 1] == '.' && s[0][w] == '#') {
            dp[0][w] = dp[0][w - 1] + 1;
        } else {
            dp[0][w] = dp[0][w - 1];
        }
    }
    for (int h = 1; h < H; h++) {
        if (s[h - 1][0] == '.' && s[h][0] == '#') {
            dp[h][0] = dp[h - 1][0] + 1;
        } else {
            dp[h][0] = dp[h - 1][0];
        }
    }
    for (int h = 1; h < H; h++) {
        for (int w = 1; w < W; w++) {
            int tmp = 1e9;
            if (s[h][w] == '#') {
                if (s[h][w - 1] == '#') tmp = min(dp[h][w - 1], tmp);
                if (s[h - 1][w] == '#') tmp = min(dp[h - 1][w], tmp);
                if (s[h][w - 1] == '.') tmp = min(dp[h][w - 1] + 1, tmp);
                if (s[h - 1][w] == '.') tmp = min(dp[h - 1][w] + 1, tmp);
            }
            if (s[h][w] == '.') {
                tmp = min(tmp, min(dp[h][w - 1], dp[h - 1][w]));
            }
            dp[h][w] = tmp;
        }
    }

    // for (int h = 0; h < H; h++) {
    // for (int w = 0; w < W; w++) {
    // cout << std::right << std::setw(2) << dp[h][w] << " ";
    // }
    // cout << endl;
    // }
    cout << dp[H - 1][W - 1] << endl;

    return 0;
}
