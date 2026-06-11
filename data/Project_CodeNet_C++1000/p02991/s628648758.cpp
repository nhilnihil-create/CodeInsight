#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int S, T, N, M;
vector<vector<int>> G;

ll solve() {
    queue<P> que;
    vector<vector<ll>> d(N, vector<ll>(3, -1));
    que.push(P(S - 1, 0));
    d[S - 1][0] = 0;
    while (!que.empty()) {
        P p = que.front(); que.pop();
        int v = p.first, n = p.second;
        rep(i, G[v].size()) {
            int to = G[v][i];
            if (d[to][(n + 1) % 3] == -1) {
                d[to][(n + 1) % 3] = d[v][n] + 1;
                que.push(P(to, (n + 1) % 3));
            }
        }
    }

    if (d[T - 1][0] == -1) return -1;
    else return d[T - 1][0] / 3;
}

int main()
{
    cin >> N >> M;
    G = vector<vector<int>>(N);

    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }
    cin >> S >> T;

    cout << solve() << endl;
    return 0;
}