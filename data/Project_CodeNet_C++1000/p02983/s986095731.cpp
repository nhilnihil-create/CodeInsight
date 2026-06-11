#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    ll l, r;
    cin >> l >> r;
    ll mi = 2000000000;

    if (r - l > 2019) cout << 0;
    else {
        for (ll i = l; i < r; i++) {
            for (ll j = i + 1; j < r + 1; j++) {
                ll rem = (i * j) % 2019;
                mi = min(rem, mi);
            }
        }
        cout << mi;
    }
}
