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

    vt<int> ans;
    for (int i = n; i > 0;) {
        int t = max(0, i - m);
        for (; t < i && s[t] == '1'; t++);
        if (t == i) return cout << -1, 0;
        ans.push_back(i - t);
        i = t;
    }

    reverse(all(ans));
    for (int i : ans) cout << i << ' ';
}
