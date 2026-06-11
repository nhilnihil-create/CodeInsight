#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 1000000007;

struct Edge {
    int to;
    int weight;

    Edge(int t, int w) : to(t), weight(w) {}
};

int main() {
    int M, D;
    cin >> M >> D;

    int ans = 0;
    for (int m = 1; m <= M; ++m) {
        for (int d = 1; d <= D; ++d) {
            int d2 = d % 10;
            int d1 = d / 10;

            if (d1 >= 2 && d2 >= 2 && d1 * d2 == m) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}