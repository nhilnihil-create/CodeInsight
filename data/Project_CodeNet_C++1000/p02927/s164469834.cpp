#include <bits/stdc++.h>

using namespace std;
const int mn = 1e5 + 5;
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
using pii=pair<int, int>;

int m, d;

int main() {
    //cin.sync_with_stdio(0);
#ifdef trote
    freopen("../1.txt", "r", stdin);
#endif
    cin >> m >> d;

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= d; j++) {
            int u = j % 10, v = j / 10;
            if (u >= 2 && v >= 2)
                if (j % 10 * (j / 10) == i) ans++;
        }
    }
    cout << ans << "\n";
}