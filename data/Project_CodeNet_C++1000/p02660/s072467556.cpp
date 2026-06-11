#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 2; i * i <= n; i++) {
        ll cnt = 0;
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            // 1 + 2 + ... + k <= cntであるような最大のkを探す
            ll ok = 1, ng = cnt;
            while (abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                if (mid * (mid + 1) / 2 <= cnt) ok = mid;
                else ng = mid;
            }
            ans += ok;
        }
    }
    if (n != 1) ans++;
    cout << ans << endl;
}