#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<string> grid;
int dp[105][105];
const int inf = 1 << 30;


int main(void){
    // Your code here!
    cin >> H >> W;
    grid.resize(H);
    for (int i=0; i<H; i++) cin >> grid[i];
    
    for (int i=0; i<105; i++){
        for (int j=0; j<105; j++){
            dp[i][j] = inf;
        }
    }
    
    dp[0][0] = (grid[0][0] == '#') ? 1 : 0;
    
    for(int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            int p=0;
            if(i+1  < H && grid[i][j] == '.' && grid[i+1][j] == '#') p = 1;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + p);
            p = 0;
            if(j+1 < W && grid[i][j] == '.' && grid[i][j+1] == '#')p = 1;
            dp[i][j+1] = min(dp[i][j+1], dp[i][j] + p);
        }
    }
    // cout << dfs(0, 0) << endl;
    cout << dp[H-1][W-1] << endl;

}
