#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> sequences (k+1);
    for (ll x = k; x >= 1; x--) {
        ll c = 1;
        ll p = n;
        ll base = k/x;

        while (p > 0) {
            if (p % 2 == 1) {
                c = (c * base) % mod;
            }

            p /= 2;
            base = (base * base) % mod;
        }

        for (ll i = x+x; i <= k; i += x) {
            c = (c - sequences[i] + mod) % mod;
        }

        sequences[x] = c;
    }

    ll s = 0;
    for (ll i = 1; i <= k; i++) {
        s = (s + (i*sequences[i]) % mod) % mod;
    }
    cout << s << "\n";
}