#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    ll n, m;
    cin >> n >> m;

    vl s(n);
    rep(i, n) {
        cin >> s[i];
    }

    vl t(m);
    rep(i, m) {
        cin >> t[i];
    }

    vvl dp(n, vl(m));  // dp[i][j] : s[i]までとt[j]まででs[i]とt[j]を含む空でない整数列として等しい部分列の組の個数
    vvl rui(n+1, vl(m+1));  // rui[i][j] : dp[x][y]を 0 <= x < i, 0 <= y < j で足し合わせたもの
    rep(i, n) {
        rep(j, m) {
            if(s[i] == t[j]) {
                dp[i][j] = rui[i][j] + 1;
                dp[i][j] %= mod;
            }
            rui[i+1][j+1] = rui[i+1][j] + rui[i][j+1] + mod - rui[i][j] + dp[i][j];
            rui[i+1][j+1] %= mod;
        }
    }

    ll ans = (rui[n][m] + 1)%mod;
    out(ans);
    re0;
}