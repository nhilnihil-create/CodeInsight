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

int n, t[100005];

void inc(int x) {
    for (; x <= n; x += x & -x) t[x]++;
}

int que(int x) {
    int z = 0;
    for (; x; x -= x & -x) z += t[x];
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    int a[100005] = {}, b[100005] = {}, c[100005] = {}, d[100005] = {}, e[100005] = {}, f[100005] = {};
    ll z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], f[a[i]] = i;
    a[0] = a[n + 1] = n + 1;
    for (int i = n; i; i--) {
        int l = 0, r = f[i];
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (que(f[i]) - que(m - 1) < 1) r = m;
            else l = m;
        }
        b[f[i]] = l;
        l = 0, r = f[i];
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (que(f[i]) - que(m - 1) < 2) r = m;
            else l = m;
        }
        c[f[i]] = l;
        l = f[i], r = n + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (que(m) - que(f[i]) < 1) l = m;
            else r = m;
        }
        d[f[i]] = r;
        l = f[i], r = n + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (que(m) - que(f[i]) < 2) l = m;
            else r = m;
        }
        e[f[i]] = r;
        //for (int j = 1; j <= n; j++) cout << que(j) << ' '; cout << '\n';
        inc(f[i]);
    }
    for (int i = 1; i <= n; i++) {
        //cout << b[i] << ' ' << c[i] << ' ' << d[i] << ' ' << e[i] << '\n';
        z += 1ll * a[i] * (b[i] - c[i]) * (d[i] - i) + 1ll * a[i] * (i - b[i]) * (e[i] - d[i]);
    }
    cout << z;
}
