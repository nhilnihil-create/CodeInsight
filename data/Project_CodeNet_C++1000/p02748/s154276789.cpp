#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;
using ll = long long;

/*struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) :x((x% mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream & is, const mint & a) { return is >> a.x; }
ostream& operator<<(ostream & os, const mint & a) { return os << a.x; }*/

int main() {
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> reizouko(a);
    vector<int> renzi(b);
    rep(i, a) cin >> reizouko[i];
    rep(i, b) cin >> renzi[i];
    vector<int> x(m);
    vector<int> y(m);
    vector<int> c(m);
    rep(i, m) cin >> x[i] >> y[i] >> c[i];

    int ans = 200001;
    rep(i, m) {
        int num = reizouko[x[i] - 1] + renzi[y[i] - 1] - c[i];
        ans = min(ans, num);
    }

    sort(reizouko.begin(), reizouko.end());
    sort(renzi.begin(), renzi.end());

    int num = reizouko[0] + renzi[0];
    ans = min(ans, num);

    cout << ans << endl;
    return 0;
}
