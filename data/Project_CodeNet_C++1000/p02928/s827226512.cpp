#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    ll inner = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (a[i] > a[j]) inner++;
        }
    }

    ll ans = inner * k % MOD;
    
    ll outer = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i] > a[j]) outer++;
        }
    }
    ll x = k * (k-1) / 2 % MOD;
    ans += x * outer % MOD;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}