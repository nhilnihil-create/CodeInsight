#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    const ll mod = 1e9 + 7;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++){
            if (a[i] == a[j]) continue;
            if (a[i] > a[j]) ans = (ans + (k + 1) * k / 2) % mod;
            else
                ans = (ans + (k - 1) * k / 2) % mod;
        }
    }
    cout << ans << endl;
}