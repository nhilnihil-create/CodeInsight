#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a[n];
    int b[n-1]; rep(i,n-1) cin >> b[i];

    a[0] = b[0];
    a[n-1] = b[n-2];
    for (int i = 1; i<(n-1); i++) {
        a[i] = min(b[i-1],b[i]);
    }
    ll ans = 0;
    rep(i,n) ans += a[i];
    cout << ans << "\n";
}