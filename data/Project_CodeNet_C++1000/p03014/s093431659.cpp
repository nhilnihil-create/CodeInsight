#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];
        vector<vector<int>> row_left(n, vector<int>(m)), row_right(n, vector<int>(m)),
              col_up(n, vector<int>(m)), col_down(n, vector<int>(m));

        for (int row = 0; row < n; row++) {
                for (int col = 0; col < m; col++) {
                        if (col == 0) {
                                row_left[row][col] = -1;
                        } else {
                                row_left[row][col] = row_left[row][col - 1];
                        }
                        if (grid[row][col] == '#') row_left[row][col] = col;
                }
                for (int col = m - 1; col >= 0; col--) {
                        if (col + 1 == m) {
                                row_right[row][col] = m;
                        } else {
                                row_right[row][col] = row_right[row][col + 1];
                        }
                        if (grid[row][col] == '#') row_right[row][col] = col;
                }
        }


        for (int col = 0; col < m; col++) {
                for (int row = 0; row < n; row++) {
                        if (row == 0) {
                                col_up[row][col] = -1;
                        } else {
                                col_up[row][col] = col_up[row - 1][col];
                        }
                        if (grid[row][col] == '#') col_up[row][col] = row;
                }

                for (int row = n - 1; row >= 0; row--) {
                        if (row + 1 == n) {
                                col_down[row][col] = n;
                        } else {
                                col_down[row][col] = col_down[row + 1][col];
                        }
                        if (grid[row][col] == '#') col_down[row][col] = row;
                }
        }



        int ans = 0;
        for (int row = 0; row < n; row++) {
                for (int col = 0; col < m; col++) {
                        if (grid[row][col] == '#') continue;
                        int lamps = 1;
                        if (row - 1 >= 0) lamps += row - col_up[row - 1][col] - 1;
                        if (row + 1 < n) lamps += col_down[row + 1][col] - row - 1;
                        if (col - 1 >= 0) lamps += col - row_left[row][col - 1] - 1;
                        if (col + 1 < m) lamps += row_right[row][col + 1] - col - 1;
                        ans = max(ans, lamps);
                }
        }

        cout << ans << '\n';
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
