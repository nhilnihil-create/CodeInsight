/* blog: https://misteer.hatenablog.com/entry/JSC2019-qual-D */

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> ans(N, vector<int>(N, -1));

    // 頂点集合[l, r)からなるクリークにd以上を割り当てる
    function<void(int, int, int)> dfs =
        [&](int l, int r, int d) {
            if (r - l <= 1) return;

            int m = (l + r) / 2;
            // [l, m)と[m, r)に分割して完全に部グラフを構築
            for (int i = l; i < m; ++i) {
                for (int j = m; j < r; ++j) {
                    ans[i][j] = d;
                }
            }

            dfs(l, m, d + 1);
            dfs(m, r, d + 1);
        };
    dfs(0, N, 1);

    for (int v = 0; v < N; ++v) {
        for (int u = v + 1; u < N; ++u) {
            cout << ans[v][u] << " ";
        }
        cout << endl;
    }
    return 0;
}
