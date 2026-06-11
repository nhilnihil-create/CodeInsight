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

    vl v(n+10);
    rep(i, m) {
        ll a;
        cin >> a;
        v[a] = 1;
    }

    vl dp(n+10);  // dp[i] : i段目に上る場合の数
    dp[0] = 1;
    if(v[1] == 0) {
        dp[1] = 1;
    }
    rep(i, n) {
        if(v[i+2] == 0) {
            dp[i+2] = dp[i+1] + dp[i];
            dp[i+2] %= mod;   
        }
    }
    
    out(dp[n]);
    re0;
}