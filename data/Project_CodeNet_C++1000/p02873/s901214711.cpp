#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<ll> a(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '>') {
            a[i] = a[i + 1] + 1;
        }
    }
    bool start = false;
    for (int i = 0; i <= n; i++) {
        if (a[i] == 0) {
            if (start) {
                a[i] = a[i - 1] + 1;
            } else {
                start = true;
            }
        } else {
            if (start) {
                a[i] = max(a[i - 1] + 1, a[i]);
            }
            start = false;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += a[i];
        // cout << a[i] << ' ';
    }
    // cout << '\n';
    cout << ans << '\n';
    return 0;
}