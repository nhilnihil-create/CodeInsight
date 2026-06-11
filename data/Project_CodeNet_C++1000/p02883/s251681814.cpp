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

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll k, a[200005] = {}, f[200005] = {}, l = -1, r = 1e18 + 328;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> f[i];
    sort(a, a + n); sort(f, f + n); reverse(f, f + n);
    while (l + 1 < r) {
        ll m = (l + r) / 2, c = 0;
        for (int i = 0; i < n; i++) c += max(0ll, a[i] - m / f[i]);
        if (c <= k) r = m;
        else l = m;
    }
    cout << r;
}
