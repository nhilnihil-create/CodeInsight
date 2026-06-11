#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> res;
    for (ll i = 2; i*i < n; i++) {
        if (n%i) continue;
        res.emplace_back(i, 0);
        while (n%i == 0) {
            n /= i;
            res.back().second++;
        }
    }
    if (n != 1) res.emplace_back(n, 1);
    return res;
}

int main() {
    ll n;
    cin >> n;
    auto a = factorize(n);
    ll ans = 0;
    for (auto x : a) {
        ll e = 1;
        while(x.second - e >= 0) {
            x.second -= e;
            e++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}