#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<cstdio>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)

int main(){
    long int const mod = 1000000007;
    long int n, m;
    cin >> n >> m;
    long int s[n];
    long int t[m];
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];
    long int sm[n][m];
    long int dp[n][m];
    if (s[0] == t[0]){
        dp[0][0] = 1;
        sm[0][0] = 1;
    }else{
        dp[0][0] = 0;
        sm[0][0] = 0;  
    }
    
    
    rep(i, n-1){
        if (s[i+1] == t[0]){
            dp[i+1][0] = 1;
            sm[i+1][0] = sm[i][0] + dp[i+1][0];
        }else{
            dp[i+1][0] = 0;
            sm[i+1][0] = sm[i][0];
        }
        dp[i+1][0] %= mod;
        sm[i+1][0] %= mod;
    }
    rep(j, m-1){
        if (s[0] == t[j+1]){
            dp[0][j+1] = 1;
            sm[0][j+1] = sm[0][j] + dp[0][j+1];
        }else{
            dp[0][j+1] = 0;
            sm[0][j+1] = sm[0][j];
        }
        dp[0][j+1] %= mod;
        sm[0][j+1] %= mod;
    }

    rep(i, n - 1)rep(j, m - 1){
        if (s[i+1] == t[j+1]){
            dp[i+1][j+1] = sm[i][j] + 1;
            sm[i+1][j+1] = mod + sm[i+1][j] + sm[i][j+1] - sm[i][j] + dp[i+1][j+1];
        }else{
            dp[i+1][j+1] = 0;
            sm[i+1][j+1] = mod + sm[i+1][j] + sm[i][j+1] - sm[i][j] + dp[i+1][j+1];
        }
        dp[i+1][j+1] %= mod;
        sm[i+1][j+1] %= mod;
        // if (sm[i+1][j+1] < 0){
        //     cout << sm[i+1][j+1] << " " << sm[i+1][j] << " " << sm[i][j+1] << " " << sm[i][j] << endl;
        //     throw;
        // }
    }
    // rep(i, n){
    //     rep(j, m){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // rep(i, n){
    //     rep(j, m){
    //         cout << sm[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (sm[n-1][m-1] + 1) % mod << endl;
}
