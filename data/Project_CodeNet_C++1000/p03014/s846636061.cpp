#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;



int main(){
    int h,w;cin >> h >> w;
    vector<string> maze(h);
    rep(i,h) cin >> maze[i];

    int para[h][w];
    int parp[h][w];

    int cnt = 0;
    rep(i,h)rep(j,w){
        if(maze[i][j]=='#') {
            para[i][j] = 0;
            continue;
        }
        if(j == w-1 || maze[i][j+1]=='#') {
            para[i][j] = cnt+1;
            rep(k,cnt) para[i][j-1-k] = cnt+1;
            cnt = 0;
        }else {
            cnt++;
            para[i][j]=cnt;
        }
    }
    cnt = 0;
    rep(i,w)rep(j,h){
        if(maze[j][i]=='#') {
            parp[j][i] = 0;
            continue;
        }
        if(j == h-1 || maze[j+1][i]=='#') {
            parp[j][i] = cnt+1;
            rep(k,cnt) parp[j-1-k][i] = cnt+1;
            cnt = 0;
        }else {
            cnt++;
            parp[j][i]=cnt;
        }
    }

    int ans = 0;
    rep(i,h)rep(j,w) ans = max(ans,para[i][j]+parp[i][j]);
    cout << ans-1 << endl;
}