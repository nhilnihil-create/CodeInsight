#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ar array
#define pii pair<int, int>
#define sz(s) (int) s.size()
#define all(s) s.begin(), s.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct BIT {
    vector<ll> t;
    int n;

    BIT(int n) : n(n), t(n, 0) {}

    ll qry(int i) {
        ll ret = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1) ret += t[i];
        return ret;
    }

    void upd(int i, ll v) {
        for(; i < n; i = i | (i + 1)) t[i] += v;
    }

    BIT(vector<ll> a) : BIT(sz(a)) {
        for (int i = 0; i < sz(a); i++) upd(i, a[i]);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    BIT bit(a);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) bit.upd(x, y);
        else cout << bit.qry(y - 1) - bit.qry(x - 1) << '\n';
    }
}
