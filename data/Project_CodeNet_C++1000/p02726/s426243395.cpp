#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int res[N];

int n, x, y;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int d1 = j - i;
            int d2 = abs(i - x) + abs(j - y) + 1;
            int d3 = abs(i - y) + abs(j - x) + 1;
            int w = min({d1, d2, d3});
            res[w] += 1;
        }
    }
    for (int i = 1; i < n; i++)
        cout << res[i] << endl;
    return 0;
}
