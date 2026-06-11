#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll now = n;
    stack<ll> ans;
    while (now != 0) {
        if (now < m) {
            ans.push(now);
            now = 0;
            continue;
        }
        bool move = false;
        for (int dice = m; dice > 0; dice--) {
            if (s[now - dice] == '0') {
                now -= dice;
                ans.push(dice);
                move = true;
                break;
            }
        }
        if (!move) {
            cout << -1 << endl;
            return 0;
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
    return 0;
}

