#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ll mx = a[0];
    for (int i = 0; i < n; i++) {
        ans += max(0LL, mx - a[i]);
        mx = max(mx, a[i]);
    }
    cout << ans << '\n';
    return 0;
}
