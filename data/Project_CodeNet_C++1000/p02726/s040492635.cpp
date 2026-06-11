#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    int ans[n] = {};

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            int cur = min(j - i, abs(x - i) + abs(y - j) + 1);
            ans[cur]++;
        }

    for (int i = 1; i < n; i++)
        cout << ans[i] << '\n';
}
