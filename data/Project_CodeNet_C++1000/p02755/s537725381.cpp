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

    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= 1250; i++) {
        if (i * 2 / 25 == a && i / 10 == b) return cout << i, 0;
    }
    cout << -1;
}
