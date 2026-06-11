#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> a;

    for (ll i = 2; i*i <= n; i++) {
        if (n % i) {
            continue;
        }

        ll e = 0;
        while(n % i == 0) {
            n /= i;
            e++;
        }
        a.push_back({i, e});
    }

    if (n != 1) {
        a.push_back({n, 1});
    }

    int ans = 0;
    for (auto t : a) {
        ll c = t.second;
        ll d = 1;
        while(d <= c) {
            c -= d;
            d++;
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}