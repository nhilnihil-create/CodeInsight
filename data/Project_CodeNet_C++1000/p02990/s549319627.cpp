#include<iostream>

using namespace std;

const int MOD = 1e9+7, N = 2005;
long long dp[N][N];

int main(){
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
        }
    }

    for(int i = 1; i <= k; i++){
        cout << ( dp[n-k+1][i] * dp[k-1][i-1] )%MOD << endl;
    }


}
