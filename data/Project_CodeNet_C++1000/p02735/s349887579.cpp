#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

P dir[2] = {{0, 1}, {1, 0}};

int main() {
    int H, W; cin >> H >> W;
    //dist[i][j] : (0, 0) -> (i, j) に行くまでに踏む最小の黒マスブロックの個数
    string s[H];
    rep(i, H) cin >> s[i];
    vector<vector<int>> dist(H, vector<int>(W, INF));
    dist[0][0] = (s[0][0] == '#');
    queue<pair<int, int>> Q;
    Q.push(mp(0, 0));
    // (h, w)
    while(!Q.empty()) {
        auto q = Q.front(); Q.pop();
        rep(i, 2) {
            int h = q.first + dir[i].first, w = q.second + dir[i].second;
            if(w >= W || h >= H) continue;
            if(dist[h][w] == INF) Q.push(mp(h, w));
            int add = (s[h][w] == '#' && s[q.first][q.second] == '.');
            dist[h][w] = min(dist[h][w], dist[q.first][q.second] + add);
        }
    }
    cout << dist[H - 1][W - 1] << endl;
}
