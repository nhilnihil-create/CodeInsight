#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
#define int long long
int p[100005], n, k, q, x;
main() {
    DAU
    cin >> n >> k >> q;
    k -= q;
    while (q--) {
        cin >> x;
        ++p[x];
    }
    for (int i = 1; i <= n; ++i) {
        p[i] += k;
        if (p[i] > 0)
            cout << "Yes\n";
        else cout << "No\n";
    }
    PLEC
}
