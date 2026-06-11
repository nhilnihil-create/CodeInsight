#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep_r(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(),x.end()
#define resize(x, n) x.resize(n)
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

ll dp[2001][2001];

ll c(ll n, ll r) {
    if (n < r) return 0;
    if (dp[n][r] != -1) return dp[n][r];
    if (n == r || r == 0) return 1;
    if (r == 1) return dp[n][r] = n;
    return dp[n][r] = (c(n-1, r-1) + c(n-1, r)) % mod;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cin >> k;
    ll blue = k, red = n-k;
    for (ll i = 1; i <= k; i++) {
        ll answer = c(red+1, i) * c(blue-1, i-1) % mod;
        // printf("%lld回の場合 %lld\n", i, answer);
        cout << answer << "\n";
    }
}