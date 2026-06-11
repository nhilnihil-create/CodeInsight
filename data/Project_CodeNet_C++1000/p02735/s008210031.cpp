#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++)
        cin >> grid[i];

    vector<vector<int>> dp(H, vector<int>(W, 1<<30));

    dp[0][0] = (grid[0][0] == '#' ? 1 : 0);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!i && !j)
                continue;

            if (i) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + (grid[i][j] != grid[i-1][j]));
            }

            if (j) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + (grid[i][j] != grid[i][j-1]));
            }
        }
    }

    cout << (dp[H-1][W-1] + 1) / 2 << "\n";

    return 0;
}
