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
    vector<ll> number(n+1);
    for (ll i = 0; i < n; i++) {
        if (s.at(i) == '<') {
            up++;
            number.at(i+1) = up;
        } else up = 0;
    }
    for (ll i = n - 1; i >= 0; i--) {
        if (s.at(i) == '>') {
            down++;
            number.at(i) = max(number.at(i), down);
        } else down = 0;
        ans += number.at(i);
    }
    ans += number.at(n);
    cout << ans << endl;
    return 0;
}