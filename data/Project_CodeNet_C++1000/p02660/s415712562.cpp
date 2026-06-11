#include <bits/stdc++.h>


using namespace std;

using ll = long long;


void prime_factorize(ll N, vector<pair<ll, ll>> &res) {
    for (ll i = 2; i * i <= N; i++) {
        if (N % i != 0)
            continue;
        ll e = 0;
        while (N % i == 0) {
            e++;
            N /= i;
        }
        res.push_back(make_pair(i, e));
    }
    if (N != 1)
        res.push_back(make_pair(N, 1));
}



int main(void) {
    ll N;
    cin >> N;
    ll ans = 0;
    vector<pair<ll, ll>> res;
    prime_factorize(N, res);
    for (auto r : res) {
        ll p = r.first;
        ll e = r.second;
        for (ll use = 1; use <= e; use++) {
            e -= use;
            ans++;
        }
    }
    cout << ans << endl;
}
