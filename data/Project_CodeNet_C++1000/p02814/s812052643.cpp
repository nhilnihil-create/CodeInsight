#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

ll solve(ll n, ll m, vector<ll> &nums) {
    while (nums[0] % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) return 0;
            nums[i] /= 2;
        }
        m /= 2;
    }
    for (int i = 0; i < n; i++) if (nums[i] % 2 == 0) return 0;

    ll lcm = 1;
    for (int i = 0; i < n; i++) {
        ll g = gcd(lcm, nums[i]);
        lcm = lcm / g * nums[i];
        if (lcm > m) return 0;
    }
    return (m / lcm + 1) / 2;
}

 
int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] /= 2;
    }

    cout << solve(n, m, nums) << endl;

    return 0;
}