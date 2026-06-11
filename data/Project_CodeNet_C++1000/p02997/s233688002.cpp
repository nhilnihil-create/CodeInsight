#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;

    int r = (n - 1) * (n - 2) / 2 - k;
    if (r < 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << (n - 1) + r << endl;
    for (int i = 0; i < n - 1; i++) cout << 1 << ' ' << 2 + i << endl;
    for (int i = 2; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!r) break;
            cout << i << ' ' << j << endl;
            r--;
        }
    }
    return 0;
}
