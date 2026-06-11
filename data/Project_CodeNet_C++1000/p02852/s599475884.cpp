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

    int n, m;
    string s;
    cin >> n >> m >> s;

    vt<int> ng{n}, ok;
    for (int i = n; i > 0; i--) {
        if (s[i - 1] == '1' && s[i] == '0') {
            ok.push_back(i);
        } else if (s[i - 1] == '0' && s[i] == '1') {
            ng.push_back(i);
        }
    }
    ok.push_back(0);

    vt<int> ans;
    for (int i = n; i > 0;) {
        int t = max(0, i - m);
        auto it = upper_bound(all(ok), t, greater<int>());
        if (it == ok.end()) it--;

        int okIdx = distance(ok.begin(), it);
        if (t >= ng[okIdx]) {
            if (!okIdx || *--it == i) return cout << -1, 0;
        }

        int mv = min(i - t, i - *it);
        ans.push_back(mv);
        i -= mv;
    }

    reverse(all(ans));
    for (int i : ans) cout << i << ' ';
}
