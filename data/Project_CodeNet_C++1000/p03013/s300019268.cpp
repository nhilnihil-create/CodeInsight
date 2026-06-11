#include <iostream>
#include <cstring>
using namespace std;
const int INF = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int a[m]; for(int i=0;i<m;++i){
        cin >> a[i];
        a[i]--;
    }
    int dp[n]; memset(dp,0,sizeof(dp));
    for(int i = 0;i < m; ++i) dp[a[i]] = -1;
    if(dp[0] != -1) dp[0]++;
    if(dp[1] != -1) dp[1]++;
    if(dp[1] != -1 && dp[0] != -1) dp[1]++;
    for(int i = 2; i < n; ++i){
        if(dp[i] == -1) continue;
        if(dp[i-1] != -1) dp[i] += dp[i-1]; dp[i] %= INF;        
        if(dp[i-2] != -1) dp[i] += dp[i-2]; dp[i] %= INF;
    }
    cout << dp[n-1] << endl;
    return 0;
}