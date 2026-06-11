#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, p; cin >> n >> p;
    string s; cin >> s;
    reverse(s.begin(), s.end());

    if (p == 2 || p == 5) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if((s[i] - '0') % p == 0) ans += n - i;
        }
        cout << ans << endl;
        return 0;
    }
    
    vector<ll> dp(n + 1);
    dp[1] = 1;
    for (int i = 1; i < n; i++) dp[i + 1] = (dp[i] * 10) % p;
    for (int i = 0; i < n; i++) {
        (dp[i + 1] *= s[i] - '0') %= p;
        (dp[i + 1] += dp[i]) %= p;
    }
    vector<ll> cnt(p);
    for (auto &e: dp) cnt[e]++;

    ll ans = 0;
    for (auto &e: cnt) ans += e * (e - 1) / 2;
    cout << ans << endl;
    return 0;
}
