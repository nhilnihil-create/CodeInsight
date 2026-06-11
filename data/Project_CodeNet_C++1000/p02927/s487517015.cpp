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
    ll m, d;
    cin >> m >> d;
    ll ans = 0;
    repd(i, 1, m + 1) {
        repd(j, 1, d + 1) {
            int d1 = j % 10, d10 = j / 10;
            if (d1 >= 2 && d10 >= 2 && d1 * d10 == i)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

