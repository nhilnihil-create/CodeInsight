#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int dist[105][105];
char grid[105][105];
int dp[105][105];
int main(){
    int h,w;cin >> h >> w;
    rep(i,105)rep(j,105) grid[i][j] = '.';
    rep(i,105)rep(j,105) dp[i][j] = 10000;
    rep(i,h)rep(j,w) cin >> grid[i][j+1];
    dp[0][0] = 0;
    auto update = [&](int i,int j,int y,int x){
        if(grid[i][j]=='.' && grid[i+y][j+x]=='#'){
            dp[i+y][j+x] =  min(dp[i+y][j+x],dp[i][j] + 1);
        }else dp[i+y][j+x] =  min(dp[i+y][j+x],dp[i][j]);
        return;
    };
    rep(i,h)rep(j,w+1){
        if(j == 0){
            if(i > 0) continue;
            update(i,j,0,1);
        }else{
            update(i,j,0,1);
            update(i,j,1,0);
        }
    }
    // rep(i,h){
    //     rep(j,w) cout << dp[i][j+1] << " ";
    //     cout << endl;
    // }
    cout << dp[h-1][w] << endl;


    
}