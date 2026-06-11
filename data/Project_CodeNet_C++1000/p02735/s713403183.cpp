#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_set>

#define ll long long int
#define mod 1000000007

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll m, n;
    cin >> m >> n;
    
    vector<vector<int>> vec(m,vector<int>(n, 0));
    for(int i= 0; i<m;i++){
        for(int j = 0;j<n;j++){
            char x;
            cin >> x;
            vec[i][j] = x;
        }
    }
    
    vector<vector<int>> dp(m,vector<int>(n, 0));
    
    dp[0][0] = (vec[0][0] == '#');
    
    // for(int i = 1;i<dp.size();i++){
    //     dp[0][i] = 1e5;
    //     dp[0][j] = min(dp[0][j], dp[i][j - 1] + (vec[i][j - 1] == '.' && vec[i][j] == '#'));
    // }
    
    // for(int i = 1;i<dp.size();i++){
    //     dp[i][0] = dp[i-1][0] + (vec[i-1][0] == '.' && vec[i][0] == '#');
    // }
    
    // for(int i= 1; i<m;i++){
    //     for(int j = 1;j<n;j++){
    //         dp[i][j] = 1e5;
    //         dp[i][j] = min(dp[i][j], dp[i - 1][j] + (vec[i - 1][j] == '.' && vec[i][j] == '#'));
    //         dp[i][j] = min(dp[i][j], dp[i][j - 1] + (vec[i][j - 1] == '.' && vec[i][j] == '#'));
    //         // dp[i][j] = min(dp[i-1][j] + (vec[i-1][j] == '.' && vec[i][j] == '#')
    //         //               ,dp[i][j-1] + (vec[i][j-1] == '.' && vec[i][j] == '#'));
            
    //     }
    
    // }
    
    vector<vector<int>> f(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i + j == 0) {
        f[0][0] = (vec[0][0] == '#');
        
      } else {
        f[i][j] = (int) 1e9;
        if (i > 0) f[i][j] = min(f[i][j], f[i - 1][j] + (vec[i - 1][j] == '.' && vec[i][j] == '#'));
        if (j > 0) f[i][j] = min(f[i][j], f[i][j - 1] + (vec[i][j - 1] == '.' && vec[i][j] == '#'));
      }
    //   cout << f[i][j] << " ";
     
    }
    // cout << '\n';
  }
    
    cout << f[m-1][n-1];
}






