#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;
constexpr ll mod = 1000000007;

int main() {
    ll m, c, d;
    queue<ll> q;
    cin >> m;
    ll r = 0;
    for (ll i = 0; i < m; i++) {
        cin >> d >> c;
        while (c > 0) {
            if (c % 2) {
                c--;
                q.push(d);
            }
            d *= 2;
            c /= 2;
            r += c;
            if (d >= 10) {
                ll d1 = d % 10, d2 = d / 10;
                r += c;
                d = d1 + d2;
            }
        }
    }
    while (q.size() > 1) {
        ll d1 = q.front();
        q.pop();
        ll d2 = q.front();
        q.pop();
        ll d3 = d1 + d2;
        r++;
        if (d3 >= 10) {
            d3 = (d3 % 10) + (d3 / 10);
            r++;
        }
        q.push(d3);
    }
    cout << r << endl;
    return 0;
}
