#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end(), less<ll>());
    ll ans;
    ll th = 1e18;
    if (a[0] == 0) {
        ans = 0;
    }
    else {
        ans = 1;
        rep (i, n) {
            if (a[i] > th / ans) {
                ans = -1;
                break;
            }
            else {
                ans *= a[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
