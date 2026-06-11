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

ll n, k, r, s, p;
string t;

// グー : 0, チョキ : 1, パー : 2 とする 

ll f(ll i, ll j) {  // i回目にjを出したときの得点
    if(t[i] == 'r') {
        if(j == 2) {
            return p;
        }
        else {
            return 0;
        }
    }
    else if(t[i] == 's') {
        if(j == 0) {
            return r;
        }
        else {
            return 0;
        }
    }
    else if(t[i] == 'p') {
        if(j == 1) {
            return s;
        }
        else {
            return 0;
        }
    }
}

int main() {
    
    cin >> n >> k >> r >> s >> p >> t;

    vvl dp(n, vl(3));  // dp[i][j] : i回目にjを出したときのi回目までの合計点の最大値
    rep(i, k) {
        rep(j, 3) {
            dp[i][j] = f(i, j);
        }
    }

    rep(i, n) {
        rep(j, 3) {  // i回目にjを出したとする
            rep(x, 3) {  // i+k回目にxを出すとする
                if(i+k < n && j != x) {
                    chmax(dp[i+k][x], dp[i][j] + f(i+k, x));
                }
            }
        }
    }

    ll ans = 0;
    exrep(i, n-k, n-1) {
        ll x = 0;
        rep(j, 3) {
            chmax(x, dp[i][j]);
        }
        ans += x;
    }

    out(ans);
    re0;
}