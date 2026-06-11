#include <iostream>
#include <string>
using namespace std;

const long long MOD = 1000000007;

int main()
{
    string S;
    cin >> S;

    int n = S.size(), D = 13;

    long long dp[100001][13] = {}, num, m = 1, rest;

    dp[0][0] = 1;

    for(int k = 0; k < n; ++k){
        for(int d = 0; d < D; ++ d){
            if(S[n - 1 - k] == '?'){
                for(num = 0; num < 10; ++num){
                    rest = (d + num * m) % D;
                    dp[k + 1][rest] += dp[k][d];
                    dp[k + 1][rest] %= MOD;
                }
            }
            else{
                num = S[n - 1 - k] - '0';
                rest = (d + num * m) % D;
                dp[k + 1][rest] += dp[k][d];
                dp[k + 1][rest] %= MOD;
            }
        }
        m *= 10;
        m %= D;
    }

    cout << dp[n][5] << endl;
}
