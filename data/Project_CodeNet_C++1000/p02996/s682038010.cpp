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
ll timer = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    priority_queue<pll, vector<pll>, greater<pll>> task;
    rep(i, n) {
        pll t;
        cin >> t.second; // 仕事にかかる時間
        cin >> t.first; // 締め切り        
        task.push(t);
    }
    bool flag = true;
    rep(i, n) {
        pll t = task.top();
        task.pop();
        if (timer + t.second <= t.first) {
            timer += t.second;
            // printf("完了後の時刻%lld 締め切り%lld\n", timer, t.first);
        } else {
            flag = false;
            break;
        }
    }
    if (flag) printf("Yes\n");
    else printf("No\n");
}