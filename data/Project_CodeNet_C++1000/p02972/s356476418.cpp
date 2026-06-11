#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll ans, n;
    ans = 0;
    cin >> n;
    vector<int> a(n), b(n, 0);
    rep(i, n) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        int s = 0;
        rep(j, n/(i + 1)) {
            s += b[(j + 1)*(i + 1) -1];
        }
        if (s%2 != a[i]) {
            b[i] = 1;
            ans++;
        }
    }
    cout << ans << endl;
    rep(i, n) {
        if (b[i] == 1) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}

