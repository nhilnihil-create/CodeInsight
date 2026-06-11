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
ll n, m, r, answer;
ll a, b, c, d;

ll gcd(ll a, ll b) { // aとbの最大公約数（ユークリッドの互除法）
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { // aとbの最小公倍数
    ll c = gcd(a, b);
    return a * b / c;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    a--;
    ll x = b - (b / c) - (b / d) + (b / lcm(c, d));
    ll y = a - (a / c) - (a / d) + (a / lcm(c, d));
    printf("%lld\n", x-y);
}