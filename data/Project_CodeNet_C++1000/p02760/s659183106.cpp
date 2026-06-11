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

#define die return cout << "Yes", 0

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    vt<int> a(9);
    for (int &i : a) cin >> i;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 0; i < 9; i++) {
            if (a[i] == x) a[i] = 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (!a[i * 3] && !a[i * 3 + 1] && !a[i * 3 + 2]) die;
        if (!a[i] && !a[i + 3] && !a[i + 6]) die;
    }
    if (!a[0] && !a[4] && !a[8]) die;
    if (!a[2] && !a[4] && !a[6]) die;

    cout << "No";
}
