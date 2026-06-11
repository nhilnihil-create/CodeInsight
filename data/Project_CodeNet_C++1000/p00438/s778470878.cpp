#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
main(){
    int dp[20][20];
    int W,H,N;
    cin >> W >> H;
    while(W){
        cin >> N;
        fill(dp[0],dp[20],0);
        for(int i = 0;i < N;i++){
            int a,b;
            cin >> a >> b;
            dp[b-1][a-1] = -1;
        }
        dp[0][0] = 1;
        for(int i = 0;i < H;i++){
            for(int j = 0;j < W;j++){
                if(i && j && dp[i-1][j] == -1 && dp[i][j-1]  == -1 || (!i && !j) || dp[i][j] == -1)continue;
                      if(!i || dp[i-1][j] == -1){
                    dp[i][j] = dp[i][j-1];
                }else if(!j || dp[i][j-1] == -1){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        if(dp[H-1][W-1] == -1)dp[H-1][W-1] = 0;
        cout << dp[H-1][W-1] << endl;
        cin >> W >> H;
    }
}