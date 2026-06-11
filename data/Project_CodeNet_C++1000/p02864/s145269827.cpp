#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
using ll = long long int;

const int N_MAX = 305;
ll H[N_MAX];

int n, k;
ll dp[N_MAX][N_MAX];
const ll INF = 1E+15;

int main(){
    cin >> n >> k;
    H[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> H[i];
    }
    for(int j = 1; j <= n; j++)dp[j][0] = INF;
    dp[0][0] = 0;
    for(int i = 1; i <= n-k; i++){
        for(int j = i; j <= n; j++){
            dp[j][i] = INF;
            for(int l = i-1; l < j; l++){
                dp[j][i] = min(dp[j][i], dp[l][i-1] + max(0LL, H[j]-H[l]));
            }
        }
    }
    ll ans = INF;
    for(int j = n-k; j <= n; j++)ans = min(ans, dp[j][n-k]);
    cout << ans << endl;
    return 0;
}