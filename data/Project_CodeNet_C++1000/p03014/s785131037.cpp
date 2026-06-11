#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int H,W;
int dx[2] = {0,1};
int dy[2] = {1,0};

int dfs(vector<vector<char>> &C, vector<vector<int>> &seen, int h, int w, int step, int flag) {
    int tmp;
    if (h+dy[flag]<H && w+dx[flag]<W) {
        if (C[h+dy[flag]][w+dx[flag]]=='.' && seen[h+dy[flag]][w+dx[flag]]==-1) {
            tmp = dfs(C,seen,h+dy[flag],w+dx[flag],step+1,flag)+1;
        }
        else tmp = 1;
    }
    else tmp = 1;
    seen[h][w] = step + tmp;
    //cout << tmp << endl;
    return tmp;
}

int main(){
    cin >> H >> W;
    vector<vector<char>> C(H,vector<char>(W));
    rep(i,H) {
        string tmp;
        cin >> tmp;
        rep(j,W) {
            C[i][j] = tmp[j];
        }
    }
    vector<vector<int>> seenh(H,vector<int> (W,-1));
    vector<vector<int>> seenw(H,vector<int> (W,-1));

    rep(h,H) {
        rep(w,W) {
            if (C[h][w]=='#') continue;
            else {
                if (seenh[h][w]==-1) {
                    seenh[h][w] = dfs(C,seenh,h,w,0,0);
                }
                if (seenw[h][w]==-1) {
                    seenw[h][w] = dfs(C,seenw,h,w,0,1);
                }
            }
        }
    }

    int ans = 0;
    rep(h,H) { 
        rep(w,W) {
            ans = max(ans,seenh[h][w]+seenw[h][w]-1);
        }
    }
    cout << ans << endl;
}
