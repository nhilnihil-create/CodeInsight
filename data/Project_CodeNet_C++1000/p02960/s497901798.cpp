#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
long long MOD = 1e9 + 7;
int main(){
    string S;
    cin >> S;
    vector<vector<long long>> dp(13, vector<long long>(S.size() + 1, 0));
    vector<long long> rui(S.size());
    rui[0] = 1;
    for(int i = 1; i < S.size(); i++){
        rui[i] = rui[i - 1] * 10 % 13;
    }
    reverse(S.begin(), S.end());
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '?'){
            for(int j = 0; j < 10; j++){
                if(i == 0) {
                    dp[j][i + 1] += 1;
                    continue;
                }
                for(int k = 0; k < 13; k++){
                    if(i != 0){
                        dp[(k + j * rui[i]) % 13][i + 1] += dp[k][i];
                        dp[(k + j * rui[i]) % 13][i + 1] %= MOD;
                    }
                }
            }
        }
        else{
            long long s = S[i] - '0';
            if(i == 0){
                dp[s][i + 1] += 1;
                continue;
            }
            for(int k = 0; k < 13; k++){
                if(i != 0){
                    dp[(k + s * rui[i]) % 13][i + 1] += dp[k][i];
                    dp[(k + s * rui[i]) % 13][i + 1] %= MOD;
                }
            }
        }
    }
    cout << dp[5][S.size()] << endl;
}