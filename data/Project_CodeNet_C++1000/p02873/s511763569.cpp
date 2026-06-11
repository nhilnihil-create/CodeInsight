#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll up = 0;
    ll down = 0;
    ll ans = 0;
    vector<ll> numberup(n+1);
    vector<ll> numberdown(n+1);
    for (ll i = 0; i < n; i++) {
        if (s.at(i) == '<') {
            up++;
            numberup.at(i+1) = up;
        } else {
            up = 0;
            numberup.at(i+1) = up;
        }
    }

    for (ll i = n - 1; i >= 0; i--) {
        if (s.at(i) == '>') {
            down++;
            numberdown.at(i) = down;
        } else {
            down = 0;
            numberdown.at(i) = down;
        }
    }

    for (ll i = 0; i <= n; i++) {
        if (numberup.at(i) < numberdown.at(i)) {
            numberup.at(i) = numberdown.at(i);
        }
        ans += numberup.at(i);
    }
    cout << ans << endl;
    return 0;
}