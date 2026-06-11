#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) {
            num++;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));

    return res;
}

int main() {
    ll N;
    cin >> N;

    vector<pair<ll, ll>> primes = prime_factorize(N);
    ll ans = 0;
    for (auto p: primes) {
        int count = p.second;
        int n = 1;
        while (count >= n) {
            ans++;
            count -= n;
            n++;
        }
    }

    cout << ans << endl;
}
