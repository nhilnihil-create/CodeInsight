#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n], b[n], c[n-1];
    rep (i, n) cin >> a[i];
    rep (i, n) cin >> b[i];
    rep (i, n-1) cin >> c[i];
    int res = 0;
    rep (i, n) {
        res += b[a[i]-1];
        if (i > 0) {
            if (a[i]-a[i-1] == 1) res += c[a[i]-2];
        }
    }
    cout << res << endl;
}