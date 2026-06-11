#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define MOD 1000000007 //10^9 + 7

int main() {
    int n;
    cin >> n;

    vector<ll> nums(n);
    for (int i = 0; i < n; i ++) cin >> nums[i];

    ll res = 0;
    ll two_factor = 1;
    for (int d = 0; d < 60; d++) {
        ll even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & (1LL << d)) odd++;
            else even++;
        }
        ll add = (even * odd) % MOD * two_factor % MOD;
        res = (res + add) % MOD;
        two_factor = (two_factor * 2) % MOD;
    }

    cout  << res << endl;

    return 0;
}