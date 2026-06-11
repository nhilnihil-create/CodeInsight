#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

map<ll,ll> factor(ll x) {
    map<ll,ll> cand;
    ll p = 2;
    if (x == 1) {
        return cand;
    }
    while (p * p <= x) {
        if (x % p == 0) {
            cand[p]++;
            x /= p;
        } else {
            p++;
        }
    }
    if (x != 1) {
        cand[x]++;
    }

    return cand;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    map<ll, ll> fac_a = factor(a);
    map<ll, ll> fac_b = factor(b);

    ll ans = 0;
    for (auto it = fac_a.begin(); it != fac_a.end(); it++) {
        if (fac_b[it->first] != 0) {
            ans++;
        }
    }

    cout << ans + 1 << endl;
}

int main() {
    solve();
    return 0;
}
