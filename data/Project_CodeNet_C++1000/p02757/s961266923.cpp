#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    reverse(all(s));
    if (p % 2 == 0 || p % 5 == 0) {
        ll ans = 0;
        rep(i, 0, n) {
            if ((s[i] - '0') % p == 0) {
                ans += n - i;
            }
        }
        cout << ans << endl;
        return 0;
    }
    int mod[n + 1] = {};
    mod[0] = 1;
    int pw = 1;
    rep(i, 0, n) {
        mod[i + 1] = (mod[i] + pw * (s[i] - '0')) % p;
        pw *= 10;
        pw %= p;
    }
    map<ll, ll> mp;
    rep(i, 0, n + 1) {
        mp[mod[i]]++;
    }
    ll ans = 0;
    for (auto i : mp) {
        ans += i.second * (i.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
