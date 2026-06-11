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
    ll n, m;
    cin >> n >> m;

    vector<P> v(m);  // v[i] : (鍵iの値段, 鍵iで開けられる宝箱の集合)
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        ll x = 0;
        rep(j, b) {
            ll c;
            cin >> c;
            x += 1<<(c-1);
        }
        v[i] = make_pair(a, x);
    }

    ll N = 1<<n;
    vvl dp(m+1, vl(N, INF));  // dp[i][s] : i個目の鍵までで集合sを開けるのに必要な費用の最小値
    dp[0][0] = 0;
    rep(i, m) {
        rep(s, N) {
            chmin(dp[i+1][s], dp[i][s]);
            chmin(dp[i+1][s | v[i].second], dp[i][s] + v[i].first);
        }
    }

    if(dp[m][N-1] == INF) {
        out(-1);
    }
    else {
        out(dp[m][N-1]);
    }

    re0;
}