#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<long long>> a(n, vector<long long>(2, 0));
    for (int i=0; i<n; i++){
        long long tmp;
        cin >> tmp;
        a[i] = {tmp, i+1};
    }
    stable_sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
    long long ans = 0;
    
    for (int i=1; i<n+1; i++){
        for (int x=0; x<i+1; x++){
            int y = i-x;
            long long activity = a[i-1][0];
            int ind = a[i-1][1];
            long long val1 = 0;
            long long val2 = 0;
            if (y-1 >= 0){
                val1 = dp[x][y-1] + activity*(abs(n-(y-1)-ind));
            }
            if (x-1 >= 0){
                val2 = dp[x-1][y] + activity*(abs(ind-x));
            }
            dp[x][y] = max(val1, val2);
            if (i == n && dp[x][y] > ans){
                ans = dp[x][y];
            }
        }
    }
    
    cout << ans << endl;
    
}
