#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 998244353;
const ll INF = 1e18;
const ll IINF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vvll dp(n + 5, vll(s + 5, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] + dp[i][j]) % MOD;
            if (j + a[i] <= s) {
                dp[i + 1][j + a[i]] += dp[i][j];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][s] << '\n';
    return 0;
}