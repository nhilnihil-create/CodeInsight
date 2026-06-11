#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
int N;

void solve() {
    cin >> N;
    ll A[N];
    for (int i = 0; i < N; ++i) { cin >> A[i]; }

    ll ans = 0;
    for (int i = 0; i < 60; ++i) {
        ll odd = 0;
        for (int j = 0; j < N; ++j) {
            if (A[j] >> i & 1) odd++;
        }
        ll even = N - odd;
        ll x = even * odd % MOD;
        for (int j = 0; j < i; ++j) { x = 2 * x % MOD; }
        ans += x;
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
