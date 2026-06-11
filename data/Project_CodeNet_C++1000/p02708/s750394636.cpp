#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;

int main() {
    ll n, k, ans = 0;
    cin >> n >> k;

    vector<ll> arr(n+1, 0);
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i-1] + i) % mod;
    }

    // for (auto x : arr) cout << x << " "; cout << endl;

    for (int i = k; i <= n; i++) {
        ll sm = arr[i-1], lr = (((arr[n] - arr[n-i])%mod) + mod) % mod;
        // cout << "i " << i << " sm " << sm << " lr " << lr << endl;
        ans = (ans + ((lr - sm) % mod + 1) % mod) % mod;
    }
    cout << ((ans+1) % mod + mod) % mod << endl;
}