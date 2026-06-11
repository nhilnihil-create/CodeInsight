#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>
#include <cstdint>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;

const int INF = 1 << 30;
const int MOD = 1e9 + 7;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n); rep(i, n) cin >> a[i];
    int s = 0;
    rep(i, n) s += a[i];

    vector<int> divisor;
    for (int i = 1; i * i <= s; i++) {
        if (i * i == s) {
            divisor.push_back(i);
            break;
        }
        if (s % i == 0) {
            divisor.push_back(i);
            divisor.push_back(s/i);
        }
    }

    int ans = 1;
    for (int d: divisor) {
        vector<int> b(n);
        rep(i, n) {
            b[i] = a[i] % d;
        }
        sort(b.begin(), b.end());
        vector<ll> upcum(n+1, 0);
        vector<ll> downcum(n+1, 0);
        rep(i, n) {
            upcum[i+1] = upcum[i] + (d - b[i]);
            downcum[i+1] = downcum[i] + b[i];
        }

        ll mi = 1L << 60;
        rep(i, n+1) {
            mi = min(mi, max(downcum[i], (upcum[n] - upcum[i])));
        }
        if (mi <= k) ans = max(ans, d);
    }

    cout << ans << endl;

    return 0;

}