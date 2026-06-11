#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    int n; cin >> n;
    int64_t k; cin >> k;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    int logk = 0;
    while ((1ll << logk) < k) ++logk;

    vector<vector<int>> doubling(logk, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        doubling[0][i] = a[i] - 1;
    }
    for (int i = 1; i < logk; ++i) {
        for (int j = 0; j < n; ++j) {
            doubling[i][j] = doubling[i - 1][doubling[i - 1][j]];
        }
    }

    int current = 0;
    for (int i = 0; i < 63; ++i) {
        if (!(k & (1ll << i))) continue;
        current = doubling[i][current];
    }

    cout << current + 1 << endl;
}

