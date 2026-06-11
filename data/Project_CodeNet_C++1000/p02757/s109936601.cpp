#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, p;
    string s;
    cin >> n >> p >> s;
    if (10 % p == 0) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % p == 0) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    ll t = 1, num = 0;
    vector<ll> nums(p, 0);
    nums[0] = 1;
    for (int i = n - 1; i >= 0; i--, t *= 10) {
        t %= p;
        num = (num + (s[i] - '0') * t) % p;
        nums[num]++;
    }
    ll ans = 0;
    for (auto x : nums) {
        ans += x * (x - 1) / 2;
    }
    cout << ans << endl;
}