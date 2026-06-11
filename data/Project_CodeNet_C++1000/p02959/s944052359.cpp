#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    rep(i, n + 1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ;
    ll ans = 0;
    rep(i, n) {
        if(b[i] > a[i]) {
            b[i] -= a[i];
            ans += a[i];
            if(b[i] >= a[i + 1]) {
                ans += a[i + 1];
                a[i + 1] = 0;
            } else {
                a[i + 1] -= b[i];
                ans += b[i];
            }
        } else {
            ans += b[i];
        }
    }
    cout << ans << endl;
    return 0;
}