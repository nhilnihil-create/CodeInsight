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

    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    vt<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') pos.push_back(i);
    }

    vt<int> lo(k), hi(k);
    lo[0] = 0, hi.back() = n - 1;
    for (int i = 1, cur = 0; i <= k; i++) {
        auto it = upper_bound(all(pos), cur + c);

        if (i != k) lo[i] = cur = *it;
        else if (it != pos.end()) return 0;
    }
    for (int i = k - 2, cur = n - 1; i >= 0; i--) {
        auto it = lower_bound(all(pos), cur - c);

        hi[i] = cur = *--it;
    }

    for (int i = 0; i < k; i++) {
        if (lo[i] == hi[i]) cout << lo[i] + 1 << '\n';
    }
}
