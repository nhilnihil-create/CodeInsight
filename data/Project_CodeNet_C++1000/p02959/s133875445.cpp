#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n);
    rep(i,n+1) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i]) {
            ans += b[i];
        }
        else {
            ans += a[i];
            b[i] -= a[i];
            if (a[i+1] >= b[i]) {
                ans += b[i];
                a[i+1] -= b[i];
            }
            else {
                ans += a[i+1];
                a[i+1] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}