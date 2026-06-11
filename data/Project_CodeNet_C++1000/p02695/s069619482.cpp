#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

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
int n, m, q;
vector<int> a(0);
vector<int> b(0);
vector<int> c(0);
vector<int> d(0);
int ans = 0;

void dfs(vector<int> a_array) {
    if (a_array.size() == n) {
        int num = 0;
        rep(i, q) {
            if (a_array[b[i] - 1] - a_array[a[i] - 1] == c[i])
                num += d[i];
        }
        ans = max(num, ans);
    }
    else {
        int num = 1;
        if (a_array.size() != 0)
            num = a_array[a_array.size() - 1];
        for (int i = num; i <= m; i++) {
            a_array.emplace_back(i);
            dfs(a_array);
            a_array.erase(a_array.begin() + a_array.size() - 1);
        }
    }
}

int main() {
    cin >> n >> m >> q;
    rep(i, q) {
        int ai, bi, ci, di;
        cin >> ai >> bi >> ci >> di;
        a.emplace_back(ai);
        b.emplace_back(bi);
        c.emplace_back(ci);
        d.emplace_back(di);
    }
    vector<int> a_array(0,0);
    dfs(a_array);
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