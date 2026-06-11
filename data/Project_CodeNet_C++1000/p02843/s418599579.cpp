#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ll x;
    cin >> x;

    vector<bool> dp(x + 1);
    dp[0] = true;

    rep(i, x) {
        if (dp[i]) {
            rep(j, 6) {
                if (i + 100 + j <= x)
                    dp[i + 100 + j] = true;
            }
        }
    }

    dp[x] ? cout << "1" : cout << "0";
    cout << endl;

    return 0;
}