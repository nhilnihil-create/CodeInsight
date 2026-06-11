#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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
 
int main() {
    ll n, W;
    cin >> n >> W;
    
    vector<P> p(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    sort(all(p));
    
    vvl dp(n, vl(W));  // dp[i][j] : i番目の料理までで食べるのにかかる時間の総和がj以下のときの美味しさの合計の最大値
    rep(i, n-1) {
        exrep(j, 0, W-1) {
            chmax(dp[i+1][j], dp[i][j]);
            if(j + p[i].first < W) {
                chmax(dp[i+1][j + p[i].first], dp[i][j] + p[i].second);
            }
        }
    }
    
    ll ans = 0;
    rep(i, n) {  // i番目の料理まで時間を使って食べるとする
        chmax(ans, dp[i][W-1] + p[i].second);
    }
 
    out(ans);
    re0;
}