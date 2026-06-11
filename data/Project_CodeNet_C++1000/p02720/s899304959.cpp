#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
using namespace std;

void solver(int d, int64_t v, vector<int64_t> &all) {
    all.push_back(v);
    if (d == 10) return;

    for (int i = -1; i <= 1; ++i) {
        int add = (v % 10) + i;
        if (add < 0 || 9 < add) continue;

        solver(d + 1, v * 10 + add, all);
    }
}

int main() {
    int k; cin >> k;

    vector<int64_t> all;
    for (int i = 1; i <= 9; ++i) solver(1, i, all);
    sort(all.begin(), all.end());

    cout << all[k - 1] << endl;
}

