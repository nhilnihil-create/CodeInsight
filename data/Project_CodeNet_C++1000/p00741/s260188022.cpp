#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
int H,W;
void dfs(int h,int w,vector<vector<int> > &table){
    //cout << h << " " << w << endl;
    table[h][w] = 0;
    int dx[] = {-1,-1,-1,0 ,0,1 ,1,1};
    int dy[] = {-1,0 ,1 ,-1,1,-1,0,1};
    rep(i,0,8){
        int nx = w + dx[i];
        int ny = h + dy[i];
        if (nx >= W || nx < 0 || ny >= H || ny < 0) continue;
        if(table[ny][nx])dfs(ny,nx,table);
    }
}
main(){
    cin >> W >> H;
    vector< vector<int> > table;
    while(W){
        table = vector< vector<int> > (H,vector<int>(W) );
        rep(i,0,H)rep(j,0,W)cin >> table[i][j];
        int cnt = 0;
        rep(i,0,H)rep(j,0,W){
            if(table[i][j] == 1){
                //cout << i << " " << j << endl;
                dfs(i,j,table);
                cnt++;
            }
        }
        cout << cnt << endl;
        cin >> W >> H;
    }
}
