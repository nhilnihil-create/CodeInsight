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
    vector<ll> a(n);

    vector<ll> output;

    atcoder::fenwick_tree<ll> fw(n);
    rep(i, n) {
        ll x;
        cin >> x;
        fw.add(i, x);
    }
    rep(i, q) {
        bool num;
        cin >> num;
        if (!num) {
            ll p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            ll l, r;
            cin >> l >> r;
            output.push_back(fw.sum(l, r));
        }
    }

    for (auto elem : output) {
        cout << elem << endl;
    }
    return 0;
}

