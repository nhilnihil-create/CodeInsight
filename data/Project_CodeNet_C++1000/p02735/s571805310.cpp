#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9+7;
int dx[] = {1,0};
int dy[] = {0,1};


int main(){
    int H,W;
    cin>>H>>W;
    char s[100+10][100+10];

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>s[i][j];
        }
    }

    vector<vector<int>> dp(H+50,vector<int>(W+50,INF));

    dp[0][0] = 0;
    if(s[0][0] == '#') dp[0][0]++;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            for(int k=0; k<2; k++){

                int nx = j + dx[k];
                int ny = i + dy[k];
                if(ny >= H || nx >= W) continue;
                if(s[i][j] == '.' && s[ny][nx] == '#') dp[ny][nx] = min(dp[ny][nx],dp[i][j]+1);
                else dp[ny][nx] = min(dp[ny][nx],dp[i][j]);
            }
        }
    }

    cout<<dp[H-1][W-1]<<endl;

    return 0;
}
