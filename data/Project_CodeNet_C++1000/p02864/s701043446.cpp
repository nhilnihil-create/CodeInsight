#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int N, K;
int H[301];
int h[301];
ll dp[301][301][301];
ll dp_min1[301][301][301]; // min{dp[i][j][k]}
ll dp_min2[301][301][301]; // min{dp[i][j][k]+H[k]-H[i]}

const ll INF = 1e+15;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> H[i+1];
        h[i+1] = H[i+1];
    }
    sort(h, h+N+1);
    for(int i = 0; i <= K; i++){
        for(int k = 0; k <= N; k++){
            dp[0][i][k] = INF;
            dp_min1[0][i][k] = INF;
            dp_min2[0][i][k] = INF;
        }
    }
    dp[0][0][0] = 0;
    dp_min1[0][0][0] = 0;
    dp_min2[0][0][0] = 0;
    for(int j = 0; j <= K; j++){
        dp_min1[0][j][0] = dp[0][j][0];
        for(int k = 1; k <= N; k++){
            dp_min1[0][j][k] = min(dp[0][j][k], dp_min1[0][j][k-1]+h[k]-h[k-1]); 
        }
    }
    for(int j = 0; j <= K; j++){
        dp_min2[0][j][N] = dp[0][j][N];
        for(int k = N-1; k >= 0; k--){
            dp_min2[0][j][k] = min(dp[0][j][k], dp_min2[0][j][k+1]);                 
        }
    }
    // for(int i = 1; i <= N; i++)cout << h[i] << ' ';
    // cout << endl;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){
            for(int k = 0; k <= N; k++){
                if(h[k] != H[i]){
                    if(j >= 1) dp[i][j][k] = min({dp[i-1][j-1][k], dp_min1[i-1][j-1][k], dp_min2[i-1][j-1][k]}); 
                    else dp[i][j][k] = INF;
                }else{
                    dp[i][j][k] = min({dp[i-1][j][k], dp_min1[i-1][j][k], dp_min2[i-1][j][k]}); 
                }
            }
        }
        for(int j = 0; j <= K; j++){
            dp_min1[i][j][0] = dp[i][j][0];
            for(int k = 1; k <= N; k++){
                dp_min1[i][j][k] = min(dp[i][j][k], dp_min1[i][j][k-1]+h[k]-h[k-1]); 
            }
        }
        for(int j = 0; j <= K; j++){
            dp_min2[i][j][N] = dp[i][j][N];
            for(int k = N-1; k >= 0; k--){
                dp_min2[i][j][k] = min(dp[i][j][k], dp_min2[i][j][k+1]);                 
            }
        }
        // for(int j = 0; j <= K; j++){
        //     for(int k = 0; k <= N; k++){
        //         cout << dp[i][j][k] << ' ';            
        //     }
        //     cout << endl;
        // }
    }
    ll ans = INF;
    for(int j = 0; j <= K; j++){
        for(int k = 0; k <= N; k++){
            ans = min(ans, dp[N][j][k]);   
            // cout << dp[N][j][k] << ' ';            
        }
        // cout << endl;
    }
    cout << ans << endl;
}