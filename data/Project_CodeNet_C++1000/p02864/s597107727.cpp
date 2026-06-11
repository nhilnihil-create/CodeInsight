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
    ll n, k;
    cin >> n >> k;
    
    vl h(n+1);
    exrep(i, 1, n) {
        cin >> h[i];
    }

    // 1項も残さない場合
    if(n == k) {
        out(0);
        re0;
    }

    // 以下1項以上残す

    vvl dp(n+1, vl(n+1, INF));  // dp[x][y] : 残った項の最も右の項の番号がx、h[1]からh[x]で残った項数がyのときのコストの最小値
    
    exrep(x, 1, n) {
        dp[x][1] = h[x];
    }
    exrep(x, 2, n) {
        exrep(y, 2, x) {
            exrep(i, 1, x-1) {
                chmin(dp[x][y], dp[i][y-1] + max(0LL, h[x] - h[i]));
            }
        }
    }
    
    ll ans = INF;
    exrep(i, 1, n) {
        chmin(ans, dp[i][n-k]);
    }
    
    out(ans);
    re0;
}