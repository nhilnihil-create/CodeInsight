#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

vector<vector<ll>> cnt;
vector<vector<bool>> seen;
int H, W;

void dfs(Graph &G, int h, int w, int fh, int fw){
    if(G[h][w] == 1 && G[fh][fw] == 0){
        cnt[h][w] = min(cnt[h][w], cnt[fh][fw] + 1);
    }else{
        cnt[h][w] = min(cnt[h][w], cnt[fh][fw]);
    }
    if(h == H - 1 && w == W - 1) return;
    if(h + 1 < H){
        dfs(G, h + 1, w, h, w);
    }
    if(w + 1 < W){
        dfs(G, h, w + 1, h, w);
    }
}

int main(){
    cin >> H >> W;
    Graph g(H, vector<int>(W));
    rep(i, H)rep(j, W){
        char c;
        cin >> c;
        if(c == '#')g[i][j] = 1;
        else g[i][j] = 0;
    }
    cnt.assign(H, vector<ll>(W, INF));
    seen.assign(H, vector<bool>(W, false));
    cnt[0][0] = g[0][0];
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            if(h - 1 >= 0){
                if(g[h][w] == 1 && g[h - 1][w] == 0) cnt[h][w] = min(cnt[h][w], cnt[h - 1][w] + 1);
                else cnt[h][w] = min(cnt[h][w], cnt[h - 1][w]);
            }
            if(w - 1 >= 0){
                if(g[h][w] == 1 && g[h][w - 1] == 0) cnt[h][w] = min(cnt[h][w], cnt[h][w - 1] + 1);
                else cnt[h][w] = min(cnt[h][w], cnt[h][w - 1]);
            }
        }
    }
    // rep(i, H){
    //     rep(j, W)cout << cnt[i][j] << " " ;
    //     cout << endl;
    // }
    int ans = cnt[H - 1][W - 1];
    cout << ans << endl;
}