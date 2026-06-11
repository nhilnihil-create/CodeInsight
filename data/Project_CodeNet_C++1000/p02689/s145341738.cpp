#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> h(n);
    for (auto &e : h) cin >> e;
    vector<array<int, 2>> edge(m);
    for (auto &e1 : edge) for (auto &e2 : e1) cin >> e2;

    vector<bool> score(n, true);
    for (auto e : edge) {
        int h1 = h[e[0] - 1];
        int h2 = h[e[1] - 1];

        if (h1 == h2) {
            score[e[0] - 1] = score[e[1] - 1] = false;
        }
        if (h1 < h2) {
            score[e[0] - 1] = false;
        }
        if (h1 > h2) {
            score[e[1] - 1] = false;
        }
    }

    int ans = 0;
    for (auto e : score) ans += e;

    cout << ans << endl;
}

