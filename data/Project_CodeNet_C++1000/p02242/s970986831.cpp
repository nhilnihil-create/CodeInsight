#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n][n];
    int done[n]; // -1: まだ ソレ以外: 確定距離
    for (int i = 0; i < n; ++i) {
        done[i] = -1;
        for (int j = 0; j < n; ++j) {
            a[i][j] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            int v, c;
            cin >> v >> c;
            a[i][v] = c;
        }
    }

    // デバッグ用
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cout << i << " " << j << " " << a[i][j] << endl;
//         }
//     }

    // 最初は0が確定済みのノードとなる
    done[0] = 0;

    // 確定済みのノードから行ける、未到達の最小のノードを探す
    // その最小のノードは次の確定済みとする...
    // とりあえずデバッグがてら10回す (最終的にwhileにして条件で対応する)
    // 全てdoneになったら終了
    for (int r = 0; r < n-1; ++r) {
        int next_node = -1;
        int next_cost = 1000000;
        for (int i = 0; i < n; ++i) {
            if (done[i] == -1) {
                // 未確定であれば何もしない
                continue;
            }

            for (int j = 0; j < n; ++j) {
                // 到達済みは見ない
                if (done[j] != -1) {
                    continue;
                }

                // コストが-1なら到達できない
                if (a[i][j] == -1) {
                    continue;
                }

                // 行けるところのコスト (iまでの距離+そこからの距離) を探す
//                cout << "src:" << i << " dst:" << j << " cost:" << a[i][j] << " total:" << done[i] + a[i][j] << endl;

                // 今のnext_costよりもtotalcostが小さければ、次のノードにしたい
                if ((done[i] + a[i][j]) < next_cost) {
                    next_cost = done[i] + a[i][j];
                    next_node = j;
                }
            }
        }
//        cout << "iter:" << r << endl;
//        cout << "next_node:" << next_node << endl;
//        cout << "next_cost:" << next_cost << endl;
        done[next_node] = next_cost;
    }

    for (int i = 0; i < n; ++i) {
        cout << i << " " << done[i] << endl;
    }

    return 0;
}
