#include <atcoder/all>
#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
const ul mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> t(q), u(q), v(q);
    rep(i, q) { cin >> t[i] >> u[i] >> v[i]; }

    atcoder::dsu d(n);

    rep(i, q) {
        if (t[i]) {
            cout << d.same(u[i], v[i]) << endl;
        } else {
            d.merge(u[i], v[i]);
        }
    }
    return 0;
}

