#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll l, r, d;
    cin >> l >> r >> d;
    ll ans = 0;
    repd(i, l, r + 1) {
        if (i % d == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}

