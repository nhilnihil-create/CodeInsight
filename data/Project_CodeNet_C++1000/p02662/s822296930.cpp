#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const double eps = 1e-9;
const ll N = 1e6 + 10;
const int M = 998244353;
const ll MAX = 1e18 + eps;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

ll be(ll b, ll e) {
    if (e == 0)
        return 1;
    if (e % 2 == 0) {
        ll x = be(b, e / 2);
        return (x * x) % M;
    } else return (b * be(b, e - 1)) % M;
}

int main() {
    ll n, s;
    cin >> n >> s;
    ll dp[n + 1][s + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = be(2, n);
    ll inv = be(2, M - 2);
    ll a[n];
    for (int k = 0; k < n; ++k) {
        cin >> a[k];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= M;
            if (j + a[i] <= s) {
                dp[i + 1][j + a[i]] += (inv * dp[i][j]) % M;
                dp[i + 1][j + a[i]] %= M;
            }
        }
    }
    cout << dp[n][s] << endl;
}