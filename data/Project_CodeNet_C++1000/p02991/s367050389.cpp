#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
    }
    int sv, tv;
    cin >> sv >> tv;
    --sv, --tv;
    vector<vector<int>> dist(n, vector<int>(3, INF));
    queue<pair<int, int>> que;
    que.push(make_pair(sv, 0));
    dist[sv][0] = 0;
    while(!que.empty()) {
        int v = que.front().first;
        int l = que.front().second;
        que.pop();
        for (auto nv : G[v]) {
            int nl = (l + 1) % 3;
            if (dist[nv][nl] != INF) continue;
            dist[nv][nl] = dist[v][l] + 1;
            que.push(make_pair(nv, nl));
        }
    }
    int ans = dist[tv][0];
    if (ans == INF) ans = -1;
    else ans /= 3;
    cout << ans << endl;
    return 0;
}