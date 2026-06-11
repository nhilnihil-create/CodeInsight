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
    ll H, n;
    cin >> H >> n;

    vl a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    
    vvl dp(n+1, vl(H+1, INF));  //  dp[i][j] : i番目までの魔法でモンスターの体力がjのとき、モンスターの体力を0以下にするのに消耗する魔力の合計の最小値
    dp[0][0] = 0;
    rep(i, n) {
        exrep(j, 0, H) {
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][min(H, j + a[i])], dp[i+1][j] + b[i]);
        }
    }

    out(dp[n][H]);
    re0;
}