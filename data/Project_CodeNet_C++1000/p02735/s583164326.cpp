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
    
    for(int i = 1;i<n;i++){
        dp[0][i] = dp[0][i-1] + (vec[0][i-1] == '.' && vec[0][i] == '#');
    }
    
    for(int i = 1;i<m;i++){
        dp[i][0] = dp[i-1][0] + (vec[i-1][0] == '.' && vec[i][0] == '#');
    }
    
    for(int i= 1; i<m;i++){
        for(int j = 1;j<n;j++){
            
            dp[i][j] = min(dp[i-1][j] + (vec[i-1][j] == '.' && vec[i][j] == '#')
                          ,dp[i][j-1] + (vec[i][j-1] == '.' && vec[i][j] == '#'));
            
        }
    
    }
    
    cout << dp[m-1][n-1];
}






