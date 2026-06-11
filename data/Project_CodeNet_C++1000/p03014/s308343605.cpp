#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using vi = vector<int>;
template <class T>
using Grid = vector<vector<T>>;

int H, W;
Grid<char> grid;
Grid<int> h,v;

int hor(Grid<char> &grid, int i, int j, int count) {
    if (j >= W)
        return count;
    if (grid[i][j] == '#') {
        h[i][j] = 0;
        return count;
    }
    return h[i][j] = hor(grid, i, j + 1, count + 1);
}
int ver(Grid<char> &grid, int i, int j, int count) {
    if (i >= H)
        return count;
    if (grid[i][j] == '#') {
        v[i][j] = 0;
        return count;
    }
    return v[i][j] = ver(grid, i + 1, j, count + 1);
}

int main() {
    cin >> H >> W;
    grid = Grid<char>(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> grid[i][j];
    h = Grid<int>(H, vector<int>(W, -1));
    v = Grid<int>(H, vector<int>(W, -1));

    rep(i, H) rep(j, W) {
        if (h[i][j] == -1)
            hor(grid, i, j, 0);
        if (v[i][j] == -1)
            ver(grid, i, j, 0);
    }
    int ans = 0;
    rep(i, H) rep(j, W) {
        ans = max(ans, h[i][j] + v[i][j]);
    }
    cout << ans - 1 << endl;
}