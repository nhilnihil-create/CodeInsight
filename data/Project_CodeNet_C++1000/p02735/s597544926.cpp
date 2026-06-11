#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<vector<int>> DP;
#define INF 1<<30

int main() {
    int H,W; cin >> H >> W;
    DP.assign(H, vector<int>(W, INF));
    vector<string> G(H);
    rep(i,H) cin >> G.at(i);
    DP[0][0] = (G[0][0] == '#') ? 1 : 0;
    int dx[] = { 1, 0,-1, 0};
    int dy[] = { 0, 1, 0,-1};
    rep(i,H) {
        rep(j,W) {
            char c = G[i][j];
            rep(k,4) {
                int z = DP[i][j]; // z must be refreshed every k loop
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx < 0 || nx >= W) continue;
                if (ny < 0 || ny >= H) continue;
                char d = G[ny][nx];
                if (c == '.' && d == '#') z++; // z broken here
                chmin(DP[ny][nx], z);
            }
        }
    }
    cout << DP[H-1][W-1] << endl;
}
