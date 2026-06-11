#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;
using ll = long long;

int gcd(int x, int y);

const int INF = 1001001001;

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

/*int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    ll len = 0;
    rep(i, n) {
        len += a[i];
    }

    ll num = 0;
    ll num2 = len;
    ll diff = 0 - len;
    ll diff2;
    rep(i, n) {
        num += a[i];
        num2 -= a[i];
        diff = abs(num - num2);
        diff2 = diff;
        if (diff > diff2)
            break;
    }

    ans = abs(num - num2);
    cout << ans << endl;
    return 0;
}*/

int main() {
    int x, y;
    cin >> x >> y;
    if (x == 1 && y == 1) {
        cout << 1000000;
        return 0;
    }
    int ans = 0;
    switch (x) {
    case 1:
        ans += 300000;
        break;
    case 2:
        ans += 200000;
        break;
    case 3:
        ans += 100000;
        break;
    }
    switch (y) {
    case 1:
        ans += 300000;
        break;
    case 2:
        ans += 200000;
        break;
    case 3:
        ans += 100000;
        break;
    }
    cout << ans << endl;
    return 0;
}
/*���C�u�����ő����*/
//���[�O���b�h�̌ݏ��@
int gcd(int x, int y) {
    int num[3];
    num[0] = (x > y) ? x : y;
    num[1] = (x <= y) ? x : y;
    num[2] = num[0] % num[1];

    while (num[2]) {
        num[0] = num[1];
        num[1] = num[2];
        num[2] = num[0] % num[1];
    }

    return num[1];
}