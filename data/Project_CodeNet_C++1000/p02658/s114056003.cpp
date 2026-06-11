#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    ll a[n], ans = 1, m = pow(10, 18);
    rep(i, n) cin >> a[i];

    rep(i, n) if(a[i] == 0) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, n) {
        if(a[i] > m / ans) {
            cout << -1 << endl;
            return 0;
        }
        ans *= a[i];
    }

    cout << ans << endl;

    return 0;
}