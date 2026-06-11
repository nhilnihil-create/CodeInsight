#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, t;
    cin >> n >> t;
    vector<int>a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    
    vector<int>idx(n);
    for(int i = 0; i < n; i++){
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](int i, int j){
            return a[i] < a[j];
        });
        
        
    int dp[n+1][t+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++){
        int k = idx[i];
        for(int tt = 0; tt <= t; tt++){
            dp[i+1][tt] = max(dp[i+1][tt], dp[i][tt]);
            if(tt >= t)continue;
            if(tt + a[k] > t - 1){
                dp[i+1][t] = max(dp[i][t], b[k] + dp[i][tt]);
            }else{
                dp[i+1][tt + a[k]] = max(dp[i+1][tt + a[k]], b[k] + dp[i][tt]);
            }
        }
    }
    
    cout << dp[n][t] << endl;
     
}
