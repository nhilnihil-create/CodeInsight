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
    vector<vector<ll>> z(n);
    map<pair<ll,ll>,ll> mp;
    vector<pair<ll, ll>> p(n-1);
    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        z[a - 1].push_back(b - 1);
        z[b - 1].push_back(a - 1);
        p[i] = make_pair(a - 1, b - 1);
    }
    ll anso = 0;
    for (int i = 0; i < n - 1; i++) {
            ll g = z[i].size();
            anso = max(anso, g);
    }
    cout << anso << endl;
    queue<ll> q;
    vector<int> fl(n);
    fl[0] = 9999999;
    q.push(0);
    
    while (!q.empty()) {
        ll k = 1;
        for (int i = 0; i < z[q.front()].size(); i++) {
            if (k == fl[q.front()])k++;
            if (fl[z[q.front()][i]] == 0) {
                fl[z[q.front()][i]] = k;
                ll ak = q.front();
                ll bk = z[q.front()][i];
                mp[make_pair(min(ak, bk), max(ak, bk))] = k;
                q.push(z[q.front()][i]);
                k++;
            }
            
        }
        q.pop();
    }
    for (int i = 0; i < n - 1; i++) {
        cout << mp[p[i]] << endl;
    }
}