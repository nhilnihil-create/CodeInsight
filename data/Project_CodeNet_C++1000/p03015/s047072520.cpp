#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1000000007;

signed main () {
    string l;
    cin >> l;
    int n = l.size();
    vector < int64_t > twos(n + 1, 1), threes(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        twos[i] = (twos[i - 1] * 2) % mod;
        threes[i] = (threes[i - 1] * 3) % mod;
    }
    int64_t ans = 0;
    int i, cnt;
    for (i = 0, cnt = 0; i < n; ++i) {
        if (l[i] == '1') {
            (ans += (twos[cnt] * threes[n - i - 1]) % mod) %= mod;
            ++cnt;
        }
    }
    (ans += twos[cnt]) %= mod;
    cout << ans << '\n';
}
