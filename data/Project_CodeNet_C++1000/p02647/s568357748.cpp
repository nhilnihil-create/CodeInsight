#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n , k;
    cin >> n >> k;
    vector<ll> A(n);
    for (auto & a : A) cin >> a;

    for (ll i = 0; i < k; ++i) {
        vector<ll> B(n+1, 0);
        for (ll j = 0; j < n; ++j) {
            ll l = max(0LL, j - A[j]);
            ll r = min(n, j + A[j] + 1);
            B[l] += 1;
            B[r] -= 1;
        }
        ll cur = 0;
        for (ll j = 0; j < n; ++j) {
            cur += B[j];
            A[j] = cur;
        }

        bool ok = true;
        for (ll j = 0; j < n; ++j) {
            if (A[j] != n) {
                ok = false; break;
            }
        }
        if (ok) break;
    }

    for (auto a : A) cout << a << " ";
    cout << endl;
}
