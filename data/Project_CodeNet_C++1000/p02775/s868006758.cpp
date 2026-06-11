#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

const int INF = 10000000;
const int E_MAX = 1000005;

int dp[E_MAX][2];

int main(){
    string n;
    cin >> n;
    int e = n.length();
    n = '0' + n;
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    for(int i = 1; i <= e; i++){
        int num = n[i] - '0';
        dp[i][0] = min(dp[i-1][0] + num,dp[i-1][1] + 10 - num);
        dp[i][1] = min(dp[i-1][0] + num + 1, dp[i-1][1] + 10 - num -1);
    }
    cout << dp[e][0] << endl;
    return 0;
}