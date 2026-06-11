#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

int main(void) {
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> sum_row(h, 0), sum_col(w, 0);
    set<pair<int, int>> t;
    for (int i = 0; i < m; i++) {
        int h, w;
        cin >> h >> w;
        h--, w--;
        sum_row[h] += 1;
        sum_col[w] += 1;
        t.emplace(h, w);
    }
    int max_row = *max_element(sum_row.begin(), sum_row.end());
    int max_col = *max_element(sum_col.begin(), sum_col.end());
    vector<int> row_idx;
    vector<int> col_idx;
    for (int i = 0; i < sum_row.size(); i++) {
        if (sum_row[i] == max_row)
            row_idx.push_back(i);
    }
    for (int i = 0; i < sum_col.size(); i++) {
        if (sum_col[i] == max_col)
            col_idx.push_back(i);
    }

    int ans = max_row + max_col;
    for (auto row : row_idx) {
        for (auto col : col_idx) {
            if (t.count(pair<int, int>(row, col))) continue;
            cout << ans << endl;
            return 0;
        }
    }
    ans--;
    cout << ans << endl;

    return 0;
}