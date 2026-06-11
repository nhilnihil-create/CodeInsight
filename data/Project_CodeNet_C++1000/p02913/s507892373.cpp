#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vt<int> z(n - i);
        for (int j = 1, l = 0, r = 0; i + j < n; j++) {
            if (j <= r) z[j] = min(z[j - l], r - j + 1);
            while (i + j + z[j] < n &&
                    s[i + z[j]] == s[i + j + z[j]]) z[j]++;
            if (j + z[j] - 1 > r) l = j, r = j + z[j] - 1;

            ans = max(ans, min(j, z[j]));
        }
    }

    cout << ans;
}
