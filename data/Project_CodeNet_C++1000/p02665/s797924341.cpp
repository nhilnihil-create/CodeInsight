#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using vvs = vector<vs>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    rep(i, (int)v.size()) {
        if (i)
            os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
    for (auto val : array)
        std::cout << val << ", ";
    std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::setprecision(10);

    ll n; std::cin >> n;
    if (n == 0) {
        int a; std::cin >> a;
        if (a == 1) std::cout << 1 << "\n";
        else if (a == 0) std::cout << 0 << "\n";
        else std::cout << -1 << "\n";
        return 0;
    }
    vl a(n+1); rep(i, n+1) std::cin >> a[i];
    vector<pl> mm(n+1);
    mm[n].fi = mm[n].se = a[n];
    for (ll i = n-1; i >= 0; i--) {
        mm[i].fi = (mm[i+1].fi+1)/2 + a[i];
        mm[i].se = mm[i+1].se + a[i];
    }
    ll ans = 1 + a[n], par = 1;
    for (ll i = 1; i < n; i++) {
        ll x = min(par*2, mm[i].se);
        ans += x;
        par = x-a[i];
    }
    if (mm[0].fi <= 1 && mm[0].se >= 1) std::cout << ans << "\n";
    else std::cout << -1 << "\n";
}
