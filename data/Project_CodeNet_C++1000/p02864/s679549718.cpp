#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
const long long MAX = 1e15;
vector<vector<long long>> dp;
signed main(){
    int n, k;
    cin >> n >> k;
    v.resize(n+1);
    dp.resize(n+1);
    for(int i = 0; i <= n; i++){
        dp[i].resize(k+1,MAX);
        if(i)cin >> v[i];
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int e = 0; e <= i; e++){
            for(int j = k; j >= 0; j--){
                dp[i+1][j] = min(dp[i+1][j], dp[e][j] + max(0, v[i+1]-v[e]));
                dp[e][j] = j?dp[e][j-1]:MAX;
            }
        }
    }
    long long ans = MAX;
    for(int i = 0; i <= n; i++)for(int j = 0; j <= k; j++)ans = min(ans, dp[i][j]);
    cout << ans << endl;
}
