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
const ll mod = 998244353;
const ll INF = 1e16;
const double pi = acos(-1);

int main() {
    ll n, S;
    cin >> n >> S;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }
    
    // T ⊃ U = {x_1, x_2, …, x_k} は
    // a_(x_1) + a(x_2) + … + a(x_k) = S を満たすとする。
    // 各a_iに対して、①Tに含めない ②Tに含めてUに含めない ③Uに含める
    // の3通りがあり得る。

    vvl dp(n+1, vl(S+1));  // dp[i+1][j] : a[i]まででUに含めたものの合計がjとなる場合の数
    dp[0][0] = 1;
    rep(i, n) {
        exrep(j, 0, S) {
            dp[i+1][j] += dp[i][j];  // ①の場合
            dp[i+1][j] += dp[i][j];  // ②の場合
            dp[i+1][j] %= mod;
            if(j + a[i] <= S) {
                dp[i+1][j + a[i]] += dp[i][j];  // ③の場合
                dp[i+1][j + a[i]] %= mod;
            }
        }
    }

    out(dp[n][S]);
    re0;
}