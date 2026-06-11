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
    ll n;
    string s;
    cin >> n >> s;

    vvl dp(n, vl(n+1));  // dp[i][j] : s[i]とs[j]からはじめたとき共通する連続部分列の長さの最大値
    for(ll i = n-2; i >= 0; i--) {
        for(ll j = n-1; i < j; j--) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
            }
        }
    }

    ll ans = 0;
    rep(i, n) {
        exrep(j, i+1, n-1) {
            chmax(ans, min(j-i, dp[i][j]));
        }
    }

    out(ans);
    re0;
}