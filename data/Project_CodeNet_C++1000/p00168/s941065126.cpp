#include <iostream>
using namespace std;
int main(void){
    int n;
    int dp[31];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < 31; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    while(1){
        cin >> n;
        if(n == 0)  break;
        int x;
        x = dp[n] / 3650;
        if(dp[n]%3650 != 0) x++;
        cout << x << endl;
    }
    return 0;
}
