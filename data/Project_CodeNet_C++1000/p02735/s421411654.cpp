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
    ll h, w;
    cin >> h >> w;

    vvl board(h, vl(w));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if(s[j] == '#') {
                board[i][j] = 1;
            }
        }
    }

    vvl dp(h, vl(w, -1));  /// dp[i][j] : (i,j)に到達するための操作回数の最小値
    if(board[0][0]) {
        dp[0][0] = 1;
    }
    else {
        dp[0][0] = 0;
    }
    exrep(j, 1, w-1) {
        dp[0][j] = dp[0][j-1];
        if(board[0][j-1] == 0 && board[0][j] == 1) {
            dp[0][j]++;
        }
    }
    exrep(i, 1, h-1) {
        dp[i][0] = dp[i-1][0];
        if(board[i-1][0] == 0 && board[i][0] == 1) {
            dp[i][0]++;
        }
    }

    exrep(i, 1, h-1) {
        exrep(j, 1, w-1) {
            ll x = dp[i-1][j];
            ll y = dp[i][j-1];
            if(board[i][j]) {
                if(board[i-1][j] == 0) {
                    x++;
                }
                if(board[i][j-1] == 0) {
                    y++;
                }
            }
            dp[i][j] = min(x, y);
        }
    }

    out(dp[h-1][w-1]);
    re0;
}