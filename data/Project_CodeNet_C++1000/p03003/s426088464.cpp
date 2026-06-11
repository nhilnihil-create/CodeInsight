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

    vl s(n);
    rep(i, n) {
        cin >> s[i];
    }
    vl t(m);
    rep(i, m) {
        cin >> t[i];
    }

    vvl dp(n+1, vl(m+1));  // dp[i+1][j+1] : s[i]までとt[j]までで、s[i]とt[j]を使うときの場合の数
    vvl rui(n+1, vl(m+1));  // rui[i][j] : Σ dp[x][y] (0 <= x <= i, 0 <= y <= j)
    dp[0][0] = 1;
    rep(i, n+1) {
        rui[i][0] = 1;
    }
    rep(j, m+1) {
        rui[0][j] = 1;
    }
    rep(i, n) {
        rep(j, m) {
            if(s[i] == t[j]) {
                dp[i+1][j+1] = rui[i][j];
            } 
            rui[i+1][j+1] = (rui[i+1][j] + rui[i][j+1] + mod - rui[i][j] + dp[i+1][j+1])%mod;
        }
    }
    
    out(rui[n][m]);
    re0;
}