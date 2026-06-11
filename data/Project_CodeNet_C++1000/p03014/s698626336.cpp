#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>
#define ii pair<int, int>
#define iii pair<ii, int>
#define pq priority_queue

using namespace std;

vector<vector<int>> precalc(vector<vector<char>> grid, int dir, int h, int w) {
    if (dir == 0) {
        //left
        vector<vector<int>> ans(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            ans[i][0] = grid[i][0] == '.' ? 1 : 0;
            for (int j = 1; j < w; j++) {
                if (grid[i][j] == '.') {
                    ans[i][j] = ans[i][j - 1] + 1;
                }
                else {
                    ans[i][j] = 0;
                }
            }
        }
        return ans;
    }
    else if (dir == 1) {
        //right
        vector<vector<int>> ans(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            ans[i][w - 1] = grid[i][w - 1] == '.' ? 1 : 0;
            for (int j = w - 2; j >= 0; j--) {
                if (grid[i][j] == '.') {
                    ans[i][j] = ans[i][j + 1] + 1;
                }
                else {
                    ans[i][j] = 0;
                }
            }
        }
        return ans;
    }
    else if (dir == 2) {
        //up
        vector<vector<int>> ans(h, vector<int>(w));
        for (int i = 0; i < w; i++) {
            ans[0][i] = grid[0][i] == '.' ? 1 : 0;
            for (int j = 1; j < h; j++) {
                if (grid[j][i] == '.') {
                    ans[j][i] = ans[j - 1][i] + 1;
                }
                else {
                    ans[j][i] = 0;
                }
            }
        }
        return ans;
    }
    else if (dir == 3) {
        //down
        vector<vector<int>> ans(h, vector<int>(w));
        for (int i = 0; i < w; i++) {
            ans[h - 1][i] = grid[h - 1][i] == '.' ? 1 : 0;
            for (int j = h - 2; j >= 0; j--) {
                if (grid[j][i] == '.') {
                    ans[j][i] = ans[j + 1][i] + 1;
                }
                else {
                    ans[j][i] = 0;
                }
            }
        }
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> graph(h, vector<char>(w));
    cin.get();
    ii start;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin.get(graph[i][j]);
        }
        cin.get(); //get \n character
    }

    vector<vector<int>> l = precalc(graph, 0, h, w);
    vector<vector<int>> r = precalc(graph, 1, h, w);
    vector<vector<int>> u = precalc(graph, 2, h, w);
    vector<vector<int>> d = precalc(graph, 3, h, w);
    int max_illuminate = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] == '.') {
                max_illuminate = max(max_illuminate, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
            }
        }
    }
    cout << max_illuminate;
}