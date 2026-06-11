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
    ll n, t;
    cin >> n >> t;
    t--;

    vector<P> p(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    sort(all(p));

    vl weight(n), value(n);
    rep(i, n) {
        weight[i] = p[i].first;
        value[i] = p[i].second;
    }

    vvl dp(n+1, vl(t+1));  // dp[i+1][j] : i番目の品物までで重さの総和j以下のときの価値の総和の最大値
    rep(i, n) {
        exrep(j, 0, t) {
            chmax(dp[i+1][j], dp[i][j]);
            if(j >= weight[i]) {
                chmax(dp[i+1][j], dp[i][j - weight[i]] + value[i]);
            }
        }
    }

    ll ans = 0;
    rep(i, n) {
        chmax(ans, dp[i][t] + value[i]);
    }

    out(ans);
    re0;
}