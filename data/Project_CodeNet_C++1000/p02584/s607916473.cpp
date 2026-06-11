
// Problem: C - Walking Takahashi
// Contest: AtCoder - AtCoder Beginner Contest 175
// URL: https://atcoder.jp/contests/abc175/tasks/abc175_c
// Parsed on: 2020-09-02 13:00:09
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main() {
    using ll = long long;
    ll x, k, d;
    cin >> x >> k >> d;
    ll absx = abs(x);

    ll req = absx / d;
    if (absx % d) req++;

    if (req > k) {
        cout << absx - (k * d);
    } else {
        int req2 = req - 1;
        if ((k - req2) % 2 == 0) {
            cout << absx - (d * req2);
        } else {
            cout << (d * req) - absx;
        }
    }
    return 0;
}
