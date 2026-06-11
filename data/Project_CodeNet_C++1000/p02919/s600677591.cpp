#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[--x] = i;
    }

    ll ans = 0;
    set<int> bigger_pos{-1, n};
    for (int i = n - 1; i >= 0; i--) {
        auto itr = bigger_pos.upper_bound(a[i]);
        auto itl = itr;
        itl--;

        ll cur = 0;
        if (*itr != n) {
            auto itr2 = itr;
            itr2++;
            cur += ll(*itr2 - *itr) * (a[i] - *itl);
        }

        if (*itl != -1) {
            auto itl2 = itl;
            itl2--;
            cur += ll(*itl - *itl2) * (*itr - a[i]);
        }

        ans += cur * (i + 1);
        bigger_pos.insert(a[i]);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
