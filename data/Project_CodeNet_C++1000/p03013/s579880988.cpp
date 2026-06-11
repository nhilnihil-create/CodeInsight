#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

const ll MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    unordered_set<ll> a;
    for (ll i = 0; i < m; ++i) {
        ll ai; cin >> ai;
        a.insert(ai);
    }
    vector<ll> dp(n+1);
    dp[0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j <= min(n, i + 2); ++j) {
            if (a.count(j) == 0) {
                dp[j] += dp[i];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[n] << "\n"; 
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/