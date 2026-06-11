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

const int maxn = 5e3 + 1;
bool vis[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vis[i][j]) continue;

            for (int k = 0; i + k < j && j + k < n; k++) {
                vis[i + k][j + k] = true;
                if (s[i + k] == s[j + k]) ans = max(ans, k + 1);
                else break;
            }
        }
    }

    cout << ans;
}
