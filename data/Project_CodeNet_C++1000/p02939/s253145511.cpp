#include <bits/stdc++.h>
using namespace std;
string s;
vector <vector<int>> dp;
int main(){
    cin >> s;
    dp = vector<vector<int>>(s.length(),vector<int>(3,0));
    dp[0][1] = 1;
    dp[0][2] = 0;
    if(s.length() >= 2){
        if(s[0]==s[1]){
            dp[1][1] = max(dp[0][1],dp[0][2]);
        }else{
            dp[1][1] = max(dp[0][1],dp[0][2])+1;
        }
        dp[1][2] = 1;
    }
    if(s.length() >= 3){
        if(s[1]==s[2]){
            dp[2][1] = max(dp[1][1],dp[1][2]);
        }else{
            dp[2][1] = max(dp[1][1],dp[1][2])+1;
        }
        dp[2][2] = max(dp[0][1],dp[0][2])+1;
        //cout << dp[2][2] << endl;
    }
    if(s.length() >= 4){
        for(int i = 3; i < s.length(); i++){
            if(s[i-1]==s[i]){
                //cout << "pathA" << endl;
                dp[i][1]=dp[i-1][2]+1;
            }else{
                //cout << "pathB" << endl;
                dp[i][1]=(max(dp[i-1][1],dp[i-1][2])+1);
            }
            if((s[i]==s[i-2])&&(s[i-1]==s[i-3])){
                dp[i][2]=dp[i-2][1]+1;
            }else{
                dp[i][2]=max(dp[i-2][1]+1,dp[i-2][1]+1);
            }
        }
    }
    #if 0
    for(int j = 0; j < s.length(); j++){
        cout << s[j] << " ";
    }
    cout << endl;
    for(int i = 1; i <= 2; i++){
        for(int j = 0; j < s.length(); j++){
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
    #endif
    cout << max(dp.back()[1],dp.back()[2]) << endl;
    return 0;
}