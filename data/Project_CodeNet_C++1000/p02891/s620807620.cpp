#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    string s;
    ll k;
    cin >> s >> k;
    ll scnt = 0;
    string t = s + s;
    ll tcnt = 0;
    bool same = true;
    for (int i = 0; i < (int)s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            i++;
            scnt++;
        }
        if (s[0] != s[i]) same = false;
    }
    for (int i = 0; i < (int)t.size() - 1; i++) {
        if (t[i] == t[i + 1]) {
            i++;
            tcnt++;
        }
    }
    ll ans = scnt * k + (tcnt - 2 * scnt) * (k - 1);
    if (same) ans = (k * (ll)s.size()) / 2;
    cout << ans << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}