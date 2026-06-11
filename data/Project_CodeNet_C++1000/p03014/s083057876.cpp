#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> maze(H, vector<char>(W));
    vector<vector<int>> left(H, vector<int>(W, 0));
    vector<vector<int>> right(H, vector<int>(W, 0));
    vector<vector<int>> up(H, vector<int>(W, 0));
    vector<vector<int>> down(H, vector<int>(W, 0));

    rep(i, H) {
        rep(j, W) { cin >> maze[i][j]; }
    }

    int cur = 0;
    rep(i, H) {
        rep(j, W) {
            if (maze[i][j] == '.')
                cur++, left[i][j] = cur;
            else
                cur = 0;
        }
        cur = 0;
    }

    rep(i, H) {
        for (int j = W - 1; j > -1; j--) {
            if (maze[i][j] == '.')
                cur++, right[i][j] = cur;
            else
                cur = 0;
        }
        cur = 0;
    }

    rep(j, W) {
        rep(i, H) {
            if (maze[i][j] == '.')
                cur++, up[i][j] = cur;
            else
                cur = 0;
        }
        cur = 0;
    }

    rep(j, W) {
        for (int i = H - 1; i > -1; i--) {
            if (maze[i][j] == '.')
                cur++, down[i][j] = cur;
            else
                cur = 0;
        }
        cur = 0;
    }

    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            int temp = left[i][j] + right[i][j] + up[i][j] + down[i][j] - 3;
            ans = max(ans, temp);
        }
    }

    cout << ans << endl;
}