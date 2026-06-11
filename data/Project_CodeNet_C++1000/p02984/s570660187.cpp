#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

signed main() {
    int n;
    cin >> n;
    int a[n];
    rep (i, 0, n) cin >> a[i];
    int b[n] = {};
    rep (i, 0, n) {
        if (i % 2 == 1) {
            b[0] -= a[i];
        } else {
            b[0] += a[i];
        }
    }
    b[0] /= 2;
    rep (i, 1, n) { b[i] = a[i - 1] - b[i - 1]; }
    rep (i, 0, n) { cout << 2 * b[i] << " "; }
    cout << "\n";
}