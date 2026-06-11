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

ll gcd(ll a, ll b) {
    while (b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll po(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b % 2) c = c * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}

ll f[2000006], g[2000006];

void comb() {
    f[0] = 1;
    for (int i = 1; i <= 2000000; i++) f[i] = f[i - 1] * i % mod;
    g[2000000] = 407182070;
    for (int i = 1999999; i >= 0; i--) g[i] = g[i + 1] * (i + 1) % mod;
}

int p[200005];

int root(int x) {return p[x] < 0 ? x : p[x] = root(p[x]);}

void mer(int x, int y) {
    if ((x = root(x)) == (y = root(y))) return;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    int n, a[270000] = {}, b[270000] = {1};
    cin >> n;
    for (int i = 0; i < (1 << n); i++) cin >> a[i];
    sort(a, a + (1 << n)); reverse(a, a + (1 << n));
    for (int i = 0; i < n; i++) {
        vector<int> c;
        int d = 0;
        for (int j = 0; j < (1 << n); j++) if (b[j]) c.push_back(j);
        for (int j = 0; j < (1 << n); j++) if (!b[j]) {
            if (d < c.size() && a[j] < a[c[d]]) d++, b[j] = 1;
        }
        if (d != c.size()) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
