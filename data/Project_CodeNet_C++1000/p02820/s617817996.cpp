#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> points(256, 0);
    cin >> points['r'] >> points['s'] >> points['p'];

    string t;
    cin >> t;

    vector<char> mp(256);
    mp['r'] = 'p'; mp['p'] = 's'; mp['s'] = 'r';

    vector<char> sol(n, '-');
    for (int i = n-1; i >= k; i--) {
        if (sol[i] != '-') {
            continue;
        }
        if (t[i] != t[i-k]) {
            sol[i] = mp[t[i]];
        } else {
            sol[i] = mp[t[i]];
            sol[i-k] = t[i];
        }
    }
    for (int i = k-1; i >= 0; i--) {
        if (sol[i] == '-') {
            sol[i] = mp[t[i]];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (sol[i] == mp[t[i]]) {
            ans += points[sol[i]];
        }
    }

    cout << ans << endl;
}