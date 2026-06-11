#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n; cin >> n;
    ll a[n+1]; rep(i,n+1) cin >> a[i];
    ll b[n]; rep(i,n) cin >> b[i];
    ll ans = 0;
    ll j = 0;
    rep(i,n) {
        // bi->ai
        j = min(a[i],b[i]);
        ans += j;
        a[i] -= j;
        b[i] -= j;
        // bi->ai+1
        j = min(a[i+1],b[i]);
        ans += j;
        a[i+1] -= j;
        b[i] -= j;
    }
    cout << ans << endl;
    return 0;
}
