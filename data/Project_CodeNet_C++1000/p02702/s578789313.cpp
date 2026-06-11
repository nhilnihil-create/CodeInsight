#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll mod = 2019;

ll modpow(ll a, ll n, ll m) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = (sum[i - 1] + (s[i - 1] - '0') * modpow(10, i - 1, mod)) % 2019;
    }
    map<int, int> mp;
    for (int i : sum) {
        mp[i]++;
    }
    ll ans = 0;
    for (auto i : mp) {
        if (i.second >= 2) ans += i.second * (i.second - 1) / 2;
    }
    cout << ans << endl;
}
