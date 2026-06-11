#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int b[n-1];
    rep (i, n-1) cin >> b[i];
    ll res = b[0];
    Rep (i, 1, n-1) {
        res += min(b[i], b[i-1]);
    }
    res += b[n-2];
    cout << res << endl;
}