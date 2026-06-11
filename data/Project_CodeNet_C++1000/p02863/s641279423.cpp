#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    vector<int> a(n), b(n);
    vector<pair<int, int>> menu(n);
    for(int i=0; i<n; i++){
        cin >> menu[i].first >> menu[i].second;
    }
    sort(menu.begin(), menu.end());
    for(int i=0; i<n; i++){
        a[i] = menu[i].first;
        b[i] = menu[i].second;
    }

    vector<vector<int>> dp(n+1, vector<int>(t)), prev(n+1, vector<int>(t));
    for(int i=0; i<n; i++){
        for(int j=0; j<t; j++){
            if(j - a[i] >= 0){
                if(dp[i+1][j] < dp[i][j-a[i]] + b[i]){
                    dp[i+1][j] = dp[i][j-a[i]] + b[i];
                    prev[i+1][j] = j-a[i];
                }
            }
            
            if(dp[i+1][j] < dp[i][j]){
                dp[i+1][j] = dp[i][j];
                prev[i+1][j] = j;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i][t-1] + b[i]);
    }
    cout << ans << endl;
    return 0;
}