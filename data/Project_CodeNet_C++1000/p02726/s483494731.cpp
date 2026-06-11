#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, x, y; cin >> n >> x >> y;

    vector<int> dists(n - 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dist = j - i;
            if (i + 1 <= x + (y - x - 1) / 2) {
                dist = min(dist, abs((i + 1) - x) + abs((j + 1) - y) + 1);
            }
            ++dists[dist - 1];
        }
    }

    for (auto ans : dists) {
        cout << ans << endl;
    }
}

