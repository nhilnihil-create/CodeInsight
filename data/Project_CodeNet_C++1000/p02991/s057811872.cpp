#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<ll, pair<int, int>> P;
int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
    }

    int S, T;
    cin >> S >> T;
    S--; T--;

    vector<vector<ll>> d(3, vector<ll>(N, INF));
    priority_queue<P, vector<P>, greater<P>> que;
    d[0][S] = 0;
    que.push({0, {S, 0}});
    while (!que.empty()) {
        ll c = que.top().first;
        int v = que.top().second.first;
        int n = que.top().second.second;
        // cout << v << " " << n << " " << c << endl;
        que.pop();
        if (d[n][v] < c) continue;
        for (int to : G[v]) {
            if (d[(n + 1) % 3][to] > d[n][v] + 1) {
                d[(n + 1) % 3][to] = d[n][v] + 1;
                que.push({d[(n + 1) % 3][to], {to, (n + 1) % 3}});
            }
        }
    }

    ll ans = d[0][T];
    if (ans == INF) ans = -1;
    else ans /= 3;
    cout << ans << endl;
    return 0;
}