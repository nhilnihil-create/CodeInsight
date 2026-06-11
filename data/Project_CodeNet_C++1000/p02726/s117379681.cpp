#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    // 辺XYを使うか使わないかで場合わけをすると
    // (i, j) を固定したとき、min { | j - i | , | x - i | + 1 + | y - j | } で求められる

    // 0-indexにする
    x--;
    y--;

    // 最短距離の数を記録する配列を作る
    vector<int> count_shortest(n - 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // i, j の最短距離
            int shortest_distance = min(abs(j - i), abs(x - i) + 1 + abs(j - y));
            count_shortest.at(shortest_distance - 1)++;
        }
    }
    for (int count : count_shortest) {
        cout << count << endl;
    }
}
