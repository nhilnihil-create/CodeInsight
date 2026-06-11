#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll k, n;
    cin >> k >> n;
    vector<ll> a(n), d(n);
    rep(i, n) cin >> a[i];
    for(int i = 1; i < n; i++) {
        d[i - 1] = a[i] - a[i - 1];
        // cout << d[i] << endl;
    }
    d[n - 1] = k - a[n - 1] + a[0];
    // rep(i, n) cout << d[i];
    cout << k - *max_element(d.begin(), d.end()) << endl;
    return 0;
}