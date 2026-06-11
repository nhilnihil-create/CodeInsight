#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep_r(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(),x.end()
#define RESIZE(x, n) x.resize(n)
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ll MAX = 100000;
struct edge {
    ll from, to, weight;
    edge(ll f, ll t, ll w) : from(f), to(t), weight(w) { }
};
vector<vector<edge>> edges;
vector<vector<ll>> graph;
vector<bool> visited;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll n, k;

// ll dp[2001][2001];
vvl dp;
ll ncr(ll n, ll r) { // nCrの組み合わせ
    if (n < r) return 0;
    if (dp[n][r] != -1) return dp[n][r];
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= i; j++) {
            if (j == 0 || i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] % mod + dp[i-1][j] % mod;
        }
    }
    return dp[n][r] % mod;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // memset(dp, -1, sizeof(dp));  
    cin >> n >> k;
    dp.resize(n+1, vl(n+1, -1));
    for (ll i = 1; i <= k; i++) {
        ll answer = ncr(n-k+1, i) * ncr(k-1, i-1) % mod;
        // printf("%lld回の場合 %lld\n", i, answer);
        cout << answer << "\n";
    }
}