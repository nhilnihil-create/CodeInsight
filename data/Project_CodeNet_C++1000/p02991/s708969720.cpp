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
int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);

    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }

    int S, T;
    cin >> S >> T;
    S--; T--;

    queue<P> que;
    vector<vector<ll>> dis(3, vector<ll>(N, INF));
    dis[0][S] = 0;
    que.push({0, S}); //0 ~ 2, V
    while (!que.empty()) {
        int path = que.front().first, v = que.front().second;
        que.pop();
        int topath = (path + 1) % 3;
        for (auto to : G[v]) {
            if (dis[topath][to] == INF) {
                dis[topath][to] = dis[path][v] + 1;
                que.push({topath, to});
            }
        }
    }
    
    cout << (dis[0][T] == INF ? -1 : dis[0][T] / 3) << endl;
    return 0;
}