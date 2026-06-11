#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int p, q, r;
    cin >> p >> q >> r;

    int ans = 0;
    if (p >= q && p >= r)
        ans += q + r;
    else if (q >= p && q >= r)
        ans += p + r;
    else
        ans += p + q;

    cout << ans << endl;
    return 0;
}
