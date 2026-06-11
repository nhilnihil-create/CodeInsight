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
const int MAX_V = 3000;
vector<vector<int>> G(MAX_V);
int N, X, Y;

vector<int> dijkstra(int s) {
    vector<int> d(N, 1e9);
    priority_queue<P> que;
    d[s] = 0;
    que.push(P(s, 0));
    while (!que.empty()) {
        int v = que.top().first, c = que.top().second;
        que.pop();
        if (d[v] < c) continue;
        for (int to : G[v]) {
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                que.push(P(to, d[to]));
            }
        }
    }
    return d;
}
int main()
{
    cin >> N >> X >> Y;

    rep(i, N - 1) {
        G[i].emplace_back(i + 1);
        G[i + 1].emplace_back(i);
    }

    G[X - 1].emplace_back(Y - 1);
    G[Y - 1].emplace_back(X - 1);

    vector<int> ans(N);
    rep(i, N - 1) {
        vector<int> res = dijkstra(i);
        repd(j, i + 1, N) {
            ans[res[j]]++;
        }
    }

    rep(i, N - 1) {
        cout << ans[i + 1] << endl;
    }
    return 0;
}