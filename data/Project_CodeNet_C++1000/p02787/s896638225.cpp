
#include <bits/stdc++.h>
using namespace std;

#define DAMAGE 10000
#define N 1000
#define INF ((1<<31)-1)

int dp[N+1][DAMAGE+1];

int main(void){
    int h, n;
    cin >> h >> n;
    int damage[N+1], cost[N+1];
    for (int i = 1; i <= n; i++){
        cin >> damage[i] >> cost[i];
    }

    for (int i = 0; i <= n; i++){
        dp[i][0] = 0;
        for (int j = 1; j <= h; j++){
            dp[i][j] = INF;
        }
    }

    for (int i = 1; i <= n ; i++){
        for (int j = 0; j <= h; j++){
            if( dp[i][j] == INF ){
                continue;
            }
            if ( i+1 <= n ){
                dp[i+1][j] = min( dp[i+1][j], dp[i][j] );
            }
            
            if( j+damage[i] > h ){
                dp[i][h] = min( dp[i][h], dp[i][j] + cost[i] );
            }
            else{
                dp[i][j+damage[i]] = min( dp[i][j+damage[i]], dp[i][j] + cost[i] );
            }
            if( i+1 <= n && j+damage[i+1] > h ){
                dp[i+1][h] = min( dp[i+1][h], dp[i][j] + cost[i+1] );
            }
            else if( i+1 <= n && j+damage[i+1] <= h ){
                dp[i+1][j+damage[i+1]] = min( dp[i+1][j+damage[i+1]], dp[i][j] + cost[i+1] );
            }
        }
    }

    cout << dp[n][h] << endl;

    return 0;
}
