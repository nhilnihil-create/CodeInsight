#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {

    ll N;

    cin >> N;

    vector<ll> L(N);

    rep(i, N) {
        cin >> L[i];
    }

    sort(L.begin(), L.end());

    ll ans = 0;

    rep(i, N - 2) {
        repl (j, i + 1,  N - 1)
        {
            ll k = L[i] + L[j];
            auto iter = lower_bound(L.begin(), L.end(), k) - L.begin();
            if (iter > j) ans += (iter - j - 1);
        }
    }

    cout << ans;

    return 0;
}
