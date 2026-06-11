#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll n; string s; cin >> n >> s;
    ll r_num = 0;
    ll g_num = 0;
    ll b_num = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'R') r_num++;
        if (s[i] == 'G') g_num++;
        if (s[i] == 'B') b_num++;
    }
    ll tmp = r_num * g_num * b_num;
    ll t = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll k = 2 * j - i;
            if (k < 0 || n <= k) continue;
            if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) {
                t++;
            }
        }
    }
    cout << tmp - t << endl;
    return 0;
}