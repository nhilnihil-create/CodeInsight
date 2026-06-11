#include <iostream>
#include <vector>
using namespace std;

const int MAX_H = 1e4 * 3;
const int INF = 1e9;

void chmin(int &a, int b) {
    if (a > b) a = b;
}

int main() {
    int h, n; cin >> h >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> min_cost(MAX_H, INF);
    min_cost[0] = 0;
    for (int i = 0; i < h; i++) {
        if (min_cost[i] == INF) continue;
        for (int j = 0; j < n; j++) {
            int damage = a[j];
            int cost = b[j];
            chmin(min_cost[i + damage], min_cost[i] + cost);
        }
    }
    int ans = 1e9;
    for (int i = h; i < MAX_H; i++) {
        chmin(ans, min_cost[i]);
    }
    cout << ans << endl;
}