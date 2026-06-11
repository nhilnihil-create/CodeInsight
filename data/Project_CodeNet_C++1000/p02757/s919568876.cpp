#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,p;
    string s;

    cin >> n >> p >> s;

    reverse(s.begin(),s.end());
    if(p == 2 || p == 5) {
        ll res = 0;
        for (int i = 0; i < n; i++) {
            if((s[i] - '0') % p == 0) res += (n - i);
        }
        cout << res << endl;
        return 0;
    }

    map<ll,ll> mp;
    mp[0] = 1;
    int ten = 1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur = cur + (s[i] - '0') * ten;
        cur %= p;
        mp[cur]++;
        ten *= 10;
        ten %= p;
    }

    ll ans = 0;
    for (auto it : mp) {
        ans += (it.second) * (it.second - 1) / 2;
    }
    cout << ans << endl;
}