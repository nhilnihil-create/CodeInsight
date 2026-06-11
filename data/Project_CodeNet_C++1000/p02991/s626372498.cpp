#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> Graph[N];
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        Graph[u].push_back(v);
    }
    int S, T;
    cin >> S >> T;
    S--;
    T--;
    vector<vector<int>> dis(N, vector<int>(3, INF));
    queue<pair<int, int>> que;
    que.push(make_pair(S, 0));
    dis[S][0] = 0;
    while(!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        int now = p.first, mm = p.second;
        //cout << now << ':' << mm << endl;
        int d = dis[now][mm];
        int nextmm = (mm + 1) % 3;
        for(auto next : Graph[now]) {
            if(dis[next][nextmm] > d + 1) {
                dis[next][nextmm] = d + 1;
                que.push(make_pair(next, nextmm));
            }
        }
    }
    if(dis[T][0] == INF)
        cout << -1 << endl;
    else
        cout << dis[T][0] / 3 << endl;
}
