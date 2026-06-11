#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl

/*-- template --*/
const int MAX_N = 1e5 + 1;

vector<vector<int>>G(MAX_N);
int main() {
    int N, M; cin >> N >> M;
    rep(i, M) {
        int u, v; cin >> u >> v;
        --u, --v;
        G[u].pb(v);
    }
    int S, T; cin >> S >> T;
    --S, --T;
    vector<vector<int>> dis(MAX_N, vector<int>(3, INF));
    queue<P>Q;
    Q.push(mp(S, 0));
    dis[S][0] = 0;
    while(!Q.empty()) {
        P q = Q.front();Q.pop();
        for(int next : G[q.first]) {
            if(dis[next][(q.second + 1)%3] == INF) {
                Q.push(mp(next, (q.second + 1)%3));
            }
            dis[next][(q.second + 1)%3] = min(dis[q.first][q.second] + 1, dis[next][(q.second + 1)%3]);
        }
    }
    if(dis[T][0] == INF)cout << -1 << endl;
    else cout << dis[T][0] / 3 << endl;
}
