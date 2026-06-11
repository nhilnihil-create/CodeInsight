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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    rep(i, n) { cin >> a[i]; }
    rep(i, k) {
        ll temp[n + 1] = {};
        rep(j, n) {
            ll index_min = max(0LL, j - a[j]);
            ll index_max = min(j + a[j] + 1, n);
            temp[index_min]++;
            temp[index_max]--;
        }

        a[0] = temp[0];
        repd(j, 1, n) { a[j] = a[j - 1] + temp[j]; }

        bool all_n = true;
        rep(j, n) {
            if (a[j] != n) {
                all_n = false;
            }
        }
        if (all_n) {
            break;
        }
    }

    rep(i, n) { cout << a[i] << " "; }
    cout << endl;
    return 0;
}

