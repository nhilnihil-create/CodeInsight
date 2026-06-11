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
    int k, q;
    ll a[5003] = {};
    cin >> k >> q;
    for (int i = 0; i < k; i++) cin >> a[i];
    while (q--) {
        ll n, x, m, b[5003] = {}, c[5003] = {};
        cin >> n >> x >> m; n--;
        x %= m;
        for (int i = 1; i <= k; i++) b[i] = b[i - 1] + a[i - 1] % m;
        for (int i = 1; i <= k; i++) c[i] = c[i - 1] + (a[i - 1] % m == 0);
        ll s = b[k] * (n / k) + b[n % k] + x, t = c[k] * (n / k) + c[n % k];
        cout << n - s / m - t << '\n';
    }
}
