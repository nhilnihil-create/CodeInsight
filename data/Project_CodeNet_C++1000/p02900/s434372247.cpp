#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll GCD (ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
vector<pair<ll,ll>> prime(ll a) {
    vector<pair<ll,ll>> res;
    for (ll i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        ll num = 0ll;
        while (a % i == 0) {
            num++;
            a /= i;
        }
        res.push_back(make_pair(i, num));
    }
    if (a > 1) res.push_back(make_pair(a, 1));
    return res;
}

int main() {
    ll a, b; cin >> a >> b;
    ll g = GCD(a, b);
    auto ans = prime(g);
    cout << (int)ans.size() + 1 << endl;
    return 0;
}