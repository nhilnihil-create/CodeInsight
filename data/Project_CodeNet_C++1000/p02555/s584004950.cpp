#include<bits/stdc++.h>
// #include<atcoder/all>
using namespace std;
// using namespace atcoder;
typedef long long ll;
using P = pair<int,int>;

const int mod = 1000000007;

int main(void){
    int s;
    cin >> s;

    int dp[2020];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    for(int i = 4; i <= s; i++){
        dp[i] = dp[i - 3] + dp[i - 1];
        dp[i] %= mod;
    }
    cout << dp[s] << endl;
    return 0;
}