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

ll po(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b % 2) c = c * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    ll f[200005] = {1}, g[200005] = {};
    for (int i = 1; i <= 200000; i++) f[i] = f[i - 1] * i % mod;
    g[200000] = 750007460;
    for (int i = 199999; i >= 0; i--) g[i] = g[i + 1] * (i + 1) % mod;
    ll n, a, b;
    cin >> n >> a >> b;
    ll z = po(2, n) - 1, x = 1, y = 1;
    for (ll i = n - a + 1; i <= n; i++) x = x * i % mod;
    for (ll i = n - b + 1; i <= n; i++) y = y * i % mod;
    x = x * g[a] % mod;
    y = y * g[b] % mod;
    z -= x;
    if (z < 0) z += mod;
    z -= y;
    if (z < 0) z += mod;
    cout << z;
}
