#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

int modpow(int x, int n) {
    int ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

signed main() {
    int n, a;
    cin>>n;
    int cnt[66] = {};
    for (int i = 0; i < n; i++) {
        cin>>a;
        for (int j = 0; j < 60; j++) {
            if ((a >> j) & 1) {
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 60; i++) {
        ans += cnt[i] * (n - cnt[i]) % MOD * modpow(2, i);
        ans %= MOD;
    }
    cout<<ans<<endl;
}