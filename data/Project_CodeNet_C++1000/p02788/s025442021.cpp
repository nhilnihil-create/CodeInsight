#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int n;
ll t[400005];

void inc(int l, int r, ll v) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) t[l++] += v;
        if (r & 1) t[--r] += v;
    }
}

ll que(int x) {
    ll z = 0;
    for (x += n; x; x >>= 1) z += t[x];
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    ll d, a, z = 0;
    pair<ll, ll> b[200005] = {};
    cin >> n >> d >> a;
    for (int i = 0; i < n; i++) cin >> b[i].first >> b[i].second, b[i].second = (b[i].second - 1) / a + 1;
    sort(b, b + n);
    for (int i = 0; i < n; i++) inc(i, i + 1, b[i].second);
    for (int i = 0; i < n; i++) {
        int c = (int)(lower_bound(b, b + n, make_pair(b[i].first + d + d, 1ll * mod)) - b);
        ll q = max(0ll, que(i));
        z += q;
        inc(i, c, -q);
    }
    cout << z;
}
