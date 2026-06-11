#include <iostream>
using namespace std;
int dp[2000 + 1];

int main(void){
    int n;
    long sum = 0;
    int MOD = 1e9+7;
    
    cin >> n;
    
    dp[0] = 1;
    for (int i = 1; i < n; i++) dp[i] = 0;
    
    for (int i = 1; i <= n; i++){
        if (i >= 3){
            sum += dp[i - 3];
            sum %= MOD;
        }
        dp[i] = sum;
    }
    
    cout << dp[n] << endl;
}
