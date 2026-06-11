#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll L, R;
    cin >> L >> R;
    ll ans = 2019;
    ll mod = 2019;
    if ((L % mod == 0 || R % mod == 0)
    || (L / mod != R / mod)) {
        ans = 0;
    } else {
        for (int i = L; i < R; ++i) {
            for (int j = L + 1; j <= R; ++j) {
                ll preans = ((i % mod) * (j % mod)) % mod;
                ans = min(ans, preans);
            }
        }
    }
    cout << ans << endl;
}
