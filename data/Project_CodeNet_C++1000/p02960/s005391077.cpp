#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
int dp[100010][13]; // dp[i][j]はi桁あった時あまりがjとなる数

int main(){
    string s; cin >> s;
    int len = s.size();
    reverse(s.begin(), s.end());

    if(s.at(0) == '?'){
        for(int i = 0; i < 10; i++){
            dp[1][i] = 1;
        }
    }
    else{
        int idx = s[0] - '0';
        dp[1][idx] = 1;
    }
    int num = 1;
    for(int i = 1; i < len; i++){
        num *= 10;
        num %= 13;
        if(s.at(i) == '?'){
            for(int j = 0; j < 10; j++){
                for(int k = 0; k < 13; k++){
                    int res = (k + j * num) % 13;
                    dp[i+1][res] += dp[i][k];
                    dp[i+1][res] %= mod;
                }
            }
        }
        else{
            for(int j = 0; j < 13; j++){
                int k = s[i] - '0';
                int res = (k * num + j) % 13;
                dp[i+1][res] += dp[i][j];
                dp[i+1][res] %= mod;
            }
        }
    }
    cout << dp[len][5] << endl;
}