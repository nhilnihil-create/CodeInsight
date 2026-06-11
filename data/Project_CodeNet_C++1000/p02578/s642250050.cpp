#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ll mx = a[0];
    for (int i = 0; i < n; i++) {
        ans += max(0LL, mx - a[i]);
        mx = max(a[i], mx);
    }
    cout << ans << '\n';
}
