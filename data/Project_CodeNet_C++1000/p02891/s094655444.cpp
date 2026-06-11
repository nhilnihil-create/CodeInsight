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
        string s;
        cin >> s;
        ll z;
        cin >> z;
        ll a = 0;
        vector<ll> x;
        ll ans = 0;
        for (int i = 0; i < s.size()-1; i++) {
            a++;
            if (s.at(i) != s.at(i + 1)) {
                x.push_back(a);
                a = 0;
            }
        }
        a++;
        ll h = 0;
        if(a!=0)x.push_back(a);
        ll f = x.size();
        if (f == 1) {
            ans = z * s.size() / 2;
            cout << ans << endl;
        }
        else {
            if (s.at(0) == s.at(s.size() - 1) && x.at(0)*x.at(f-1) % 2 ==1) {
                h = z - 1;
            }
            ll ans = 0;
            for (int i = 0; i < f; i++) {
                ans += x.at(i) / 2;
            }
            cout << z * ans+h << endl;;
        }
    }