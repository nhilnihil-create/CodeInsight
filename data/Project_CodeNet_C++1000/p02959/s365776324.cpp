#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
#define int long long
int n, a[100005], res, p, x;
main() {
    DAU
    cin >> n;
    ++n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (a[i] >= x)
            res += x;
        else {
            res += a[i];
            x -= a[i];
            p = min(x, a[i+1]);
            res += p;
            a[i+1] -= p;
        }
    }
    cout << res;
    PLEC
}
