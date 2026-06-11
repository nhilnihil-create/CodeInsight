#include <iostream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
#include <tuple>

using namespace std;
mt19937_64 rng(58);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) cin >> grid[i];
    vector<vector<int>> dp(h, vector<int>(w));
    dp[0][0] = grid[0][0] == '#' ? 1 : 0;
    for (int i = 1; i < w; i++) {
        dp[0][i] = dp[0][i - 1];
        if (grid[0][i] == '#' && grid[0][i-1] == '.')
            dp[0][i]++;
    }
    for (int i = 1; i < h; i++) {
        dp[i][0] = dp[i - 1][0];
        if (grid[i][0] == '#' && grid[i - 1][0] == '.')
            dp[i][0]++;
    }
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            dp[i][j] = min(
                dp[i - 1][j] + ((grid[i][j] == '#' && grid[i - 1][j] == '.') ? 1 : 0),
                dp[i][j - 1] + ((grid[i][j] == '#' && grid[i][j - 1] == '.') ? 1 : 0)
            );
        }
    }
    cout << dp[h - 1][w - 1] << "\n";
}