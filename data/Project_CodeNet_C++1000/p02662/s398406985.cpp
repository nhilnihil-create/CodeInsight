#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

const ll mod = 998244353;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> dp(s+1, 0);
    dp[0] = 1;
    rep(i, n) {
        vector<ll> p(s+1, 0);
        swap(dp, p);
        rep(j, s+1) {
            dp[j] += (p[j] * 2) % mod;
            dp[j] %= mod;
            if (j + a[i] <= s) {
                dp[j+a[i]] += p[j];
                dp[j+a[i]] %= mod;
            }
        }
    }
    cout << dp[s] << endl;
}
