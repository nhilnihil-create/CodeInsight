#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    --x, --y;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt[min(abs(j - i), min(abs(i - x) + abs(y - j) + 1,
                                    abs(i - y) + abs(j - x) + 1))]++;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << cnt[i] << endl;
    }
    return 0;
}