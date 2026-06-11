#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
using namespace std;
using ll = long long;


unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

class UnionFind {
public:
    vector <ll> par;
    vector <ll> siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

int main() {
    ll n;
    cin >> n;
    vector<queue<ll>> z(n);
    queue<pair<ll, ll>> q;
    vector<vector<ll>> d(n, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            ll a;
            cin >> a;
            a--;
            z[i].push(a);
            if (j == 0)d[min(i, a)][max(i, a)]++;
        }
    }
    for (ll i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (d[i][j] == 2)q.push(make_pair(i, j));
        }
    }
    vector<vector<ll>> ans(n, vector<ll>(n));
    while (!q.empty()) {
        ll f = q.front().first;
        ll g = q.front().second;
        z[f].pop();
        z[g].pop();
        if (!z[f].empty()) { d[min(z[f].front(), f)][max(z[f].front(), f)]++;
        if (d[min(z[f].front(), f)][max(z[f].front(), f)] == 2) {
                ans[min(z[f].front(), f)][max(z[f].front(), f)] = ans[f][g] + 1;
                q.push(make_pair(min(z[f].front(), f), max(z[f].front(), f)));
            }
        }
        if (!z[g].empty()) { d[min(z[g].front(), g)][max(z[g].front(), g)]++;
        if (d[min(z[g].front(), g)][max(z[g].front(), g)] == 2) {
                ans[min(z[g].front(), g)][max(z[g].front(), g)] = ans[f][g] + 1;
                q.push(make_pair(min(z[g].front(), g), max(z[g].front(), g)));
            }
        }
            

            

        q.pop();
    }
    ll anss = 0;
    for (ll i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            anss = max(anss, ans[i][j]);
        }
    }
    for (ll i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i][j] != 2)anss=-2;
        }
    }
    cout << anss+1 << endl;
}