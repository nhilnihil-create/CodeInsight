#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    cin >> S;
    long long int ans = 0;
    vector<vector<long long int>> dp(S.size()+1,vector<long long int>(13,0));

    dp[0][0] = 1;

    for(int i=0;i<S.size();i++){
        int now;

        if(S[i]=='?'){
            now = -1;
        }else{
            now = S[i]-'0';
        }

        for(int j=0;j<10;j++){
            if(now!=-1 && now!=j){
                continue;
            }

            for(int k=0;k<13;k++){
                dp[i+1][(k*10+j)%13] += dp[i][k];
            }
        }

        for(int j=0;j<13;j++){
            dp[i+1][j] %= 1000000007;
        }
    }

    cout << dp[dp.size()-1][5] << endl;
}