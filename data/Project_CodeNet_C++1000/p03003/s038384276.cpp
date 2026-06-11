#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

ll ans;
ll dp[2005][2005];
ll sum[2005][2005];

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<ll> s(n+5), t(m+5);
    rep(i, 1, n+1) cin >> s[i];
    rep(i, 1, m+1) cin >> t[i];

    dp[0][0] = 1;
    rep(i, 1, n+1) rep(j, 1, m+1) {
        if (s[i]==t[j]) dp[i][j] = (sum[i-1][j-1] + 1)%MOD;
        sum[i][j] = (((sum[i-1][j] + sum[i][j-1])%MOD - sum[i-1][j-1])%MOD + dp[i][j])%MOD;
        if (sum[i][j]<0) sum[i][j] += MOD;
    }

    rep(i, 0, n+1) rep(j, 0, m+1) ans += dp[i][j] %MOD;
  
    cout << ans%MOD << "\n";
    return 0;
}

