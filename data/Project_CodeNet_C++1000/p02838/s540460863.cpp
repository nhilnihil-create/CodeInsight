#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

int main() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    ll count[64][2] = { 0 };
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];

        for (ll j = 0; j < 61; j++) {
            count[j][((arr[i] >> j) & 1) == 1]++;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < 60; i++) {
        ans = ((ans + ((count[i][1] * count[i][0]) % mod) * ((1ll << i) % mod)) % mod);
    }

    cout << ans << endl;

}

/*
1 2 3
001
010
011

2 + 4
*/