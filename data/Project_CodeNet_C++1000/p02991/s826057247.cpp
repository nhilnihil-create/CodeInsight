#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int N, M;
Graph G(100005);
vector<vector<int>> dist(100005, vector<int>(3, -1));

int main()
{
    cin >> N >> M;
    rep(i, M)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    int S, T;
    cin >> S >> T;
    S--, T--;

    queue<int> q;
    q.push(S);
    dist[S][0] = 0;
    int move = 0;

    while (!q.empty()) {
        int size = q.size();
        move++;
        for (int i = 0; i < size; i++) {
            int v = q.front();
            q.pop();
            for (int nv : G[v]) {
                if (dist[nv][move % 3] != -1)
                    continue;
                q.push(nv);
                dist[nv][move % 3] = move;
            }
        }
    }

    if (dist[T][0] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[T][0] / 3 << endl;
    }

    return 0;
}