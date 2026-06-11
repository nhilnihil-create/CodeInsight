#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

ll l, r;

int main() {
    cin >> l >> r;
    if (r - l >= 2018) {
        cout << 0 << endl;
        exit(0);
    }
    l %= 2019;
    r %= 2019;
    if (l > r) {
        cout << 0 << endl;
        exit(0);
    }
    int res = 3000;
    for (int i = l; i < r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
            res = min(res, i * j % 2019);
        }
    }
    cout << res << endl;

    return 0;
}
