/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2020
 */
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0; i < h; ++i) cin >> grid[i];
    vector<vector<int>> left(h, vector<int>(w, 0));
    vector<vector<int>> right(h, vector<int>(w, 0));
    vector<vector<int>> up(h, vector<int>(w, 0));
    vector<vector<int>> down(h, vector<int>(w, 0));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(grid[i][j] == '.') {
                // left
                if(j > 0 && grid[i][j - 1] == '.') left[i][j] = left[i][j - 1] + 1;

                // up
                if(i > 0 && grid[i - 1][j] == '.') up[i][j] = up[i - 1][j] + 1;
            }
        }
    }

    for(int i = h - 1; i >= 0; --i) {
        for(int j = w - 1; j >= 0; --j) {
            if(grid[i][j] == '.') {
                // right
                if(j + 1 < w && grid[i][j + 1] == '.') right[i][j] = right[i][j + 1] + 1;

                // down
                if(i + 1 < h && grid[i + 1][j] == '.') down[i][j] = down[i + 1][j] + 1;
            }
        }
    }
    int mx = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(grid[i][j] == '.') {
                mx = max(mx, 1 + left[i][j] + right[i][j] + up[i][j] + down[i][j]);
            }
        }
    }
    cout << mx << endl;
    return 0;
}

