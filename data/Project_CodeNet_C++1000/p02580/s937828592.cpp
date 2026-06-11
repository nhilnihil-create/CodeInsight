#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int h, w, m;
unordered_map<int, unordered_set<int>> row, col;

int main() {
    cin >> h >> w >> m;
    for (int k = 0; k < m; k++) {
        int i, j; cin >> i >> j;
        row[i].insert(j);
        col[j].insert(i);
    }
    unordered_set<int> rows_needed, cols_needed;
    size_t mx1 = 0;
    for (auto it : row) {
        mx1 = max(mx1, it.second.size());
    }
    for (auto it : row) {
        if (it.second.size() == mx1) {
            rows_needed.insert(it.first);
        }
    }
    size_t mx2 = 0;
    for (auto it : col) {
        mx2 = max(mx2, it.second.size());
    }
    for (auto it : col) {
        if (it.second.size() == mx2) {
            cols_needed.insert(it.first);
        }
    }

    for (auto it : rows_needed) {
        for (auto to_check : cols_needed) {
            if (row[it].find(to_check) == row[it].end()) {
                cout << mx1 + mx2 << endl;
                return 0;
            }
        }
    }

    cout << mx1 + mx2 - 1 << endl;
    return 0;
}