#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ul = uint32_t;
using ull = uint64_t;
using l = int32_t;
using ll = int64_t;
using namespace std;

int main() {
    fastIO;

    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    int sum = 0;

    if (a >= k) {
        cout << k;
        return 0;
    }
    sum += a;
    k -= a;

    if (b >= k) {
        cout << sum;
        return 0;
    }
    sum += 0;
    k -= b;

    if (c == k)
        cout << sum - c;
    else
        cout << sum - k;
}