#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>>cnt(N,vector<int>(3,INF));
    vector<vector<int>>ki(N);
    for(int i = 0; i < M; i++) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        ki[u].push_back(v);
    }
    int S,T;
    cin >> S >> T;
    S--;T--;
    cnt[S][0] = 0;
    queue<P>que;
    que.push({S,0});
    while (!que.empty()) {
        P x = que.front();
        que.pop();
        for(int i = 0; i < ki[x.first].size(); i++) {
            if(cnt[ki[x.first][i]][(x.second+1)%3] > cnt[x.first][x.second]+((x.second == 0)?1:0)) {
                cnt[ki[x.first][i]][(x.second+1)%3]  = cnt[x.first][x.second]+((x.second == 0)?1:0);
                que.push({ki[x.first][i],(x.second+1)%3});
            }
        }
    }
    if(cnt[T][0] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << cnt[T][0] << endl;
}
