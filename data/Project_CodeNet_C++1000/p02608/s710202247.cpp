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
    ll n;
    cin >> n;
    ll ans[n + 1] = {};
    repd(x, 1, 350) {
        repd(y, 1, 350) {
            repd(z, 1, 350) {
                ll num = x * x + y * y + z * z + x * y + y * z + z * x;
                if (num <= n) {
                    ans[num]++;
                }
            }
        }
    }

    repd(i, 1, n + 1) { cout << ans[i] << endl; }
    return 0;
}

