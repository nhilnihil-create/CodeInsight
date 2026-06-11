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

ll dp[2][100010];  /* dp[id][i+1] : 先頭からi桁目までで条件を満たすs以下の数の個数。
                                    ただし、id = 0 のとき現時点でsと等しい。
                                    id = 1 のとき現時点でsより小さいことが確定。 */

int main() {
    string s;
    cin >> s;
    ll m = s.size();  // sはm桁とする
    
    dp[0][0] = 1;
    rep(i, m) {
        // a,bのi桁目をa_i,b_iとする
        if(s[i] == '0') {  // sの先頭からi桁目が0のとき
            // (a_i, b_i) = (0, 0) のとき
            dp[0][i+1] += dp[0][i];
            dp[1][i+1] += dp[1][i];
            // (a_i, b_i) = (0, 1), (1, 0) のとき
            dp[1][i+1] += 2*dp[1][i];
        }
        else {  // sの先頭からi桁目が1のとき
            // (a_i, b_i) = (0, 0) のとき
            dp[1][i+1] += dp[0][i] + dp[1][i];
            // (a_i, b_i) = (0, 1), (1, 0) のとき
            dp[0][i+1] += 2*dp[0][i];
            dp[1][i+1] += 2*dp[1][i];
        }
        dp[0][i+1] %= mod;
        dp[1][i+1] %= mod;
    }
    
    out((dp[0][m] + dp[1][m])%mod);
    re0;
}