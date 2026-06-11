#include <iostream>
#include <vector>

using namespace std;
int n, m, x;
const int INF = 1e9 + 5;
int min_cost = INF;

int main() {
    scanf("%d %d %d", &n, &m, &x);
    vector<int> cost(n);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cost[i]);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        int cur_cost = 0;
        vector<int> cur_level(m, 0);

        for (int i = 0; i < n; ++i) {
            if ((mask >> i & 1) == 1) {
                cur_cost += cost[i];
                bool found = true;
                for (int j = 0; j < m; ++j) {
                    cur_level[j] += a[i][j];
                    if (cur_level[j] < x) {
                        found = false;
                    }
                }
                if (found) {
                    min_cost = min(min_cost, cur_cost);
                    break;
                }
            }
        }
    }


    if (min_cost == INF) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", min_cost);
    }
    return 0;
}
