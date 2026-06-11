#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll a[n+1], b[n];
    rep (i, n + 1) {
        cin >> a[i];
    }
    rep (i, n) {
        cin >> b[i];
    }
    ll res = 0;
    rep (i, n) {
        if (a[i] < b[i]) {
            res += a[i];
            b[i] -= a[i];
            if (a[i + 1] < b[i]) {
                res += a[i+1];
                a[i+1] = 0;
            } else {
                res += b[i];
                a[i + 1] -= b[i];
            }
        } else {
            res += b[i];
        }
    }
    cout << res << endl;
}