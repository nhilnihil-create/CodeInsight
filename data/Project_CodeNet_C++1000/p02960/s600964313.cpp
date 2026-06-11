#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n=s.length();
    vector<vector<long> >dp(n,vector<long>(13,0));
    if(s[0]=='?'){
        for(int i=0;i<=9;i++)dp[0][i] = 1;
    }else{
        dp[0][(int)(s[0]-'0')]=1;
    }
    long const MOD = 1e9+7;
    for(int i=1;i<n;i++){
        int num = (int)(s[i]-'0');
        for(int j=0;j<13;j++){
            if(s[i]=='?'){
                for(int k=0;k<=9;k++){
                    dp[i][(10*j+k)%13] += dp[i-1][j];
                    dp[i][(10*j+k)%13] %= MOD;
                }
            }else{
                dp[i][(10*j+num)%13] += dp[i-1][j];
                dp[i][(10*j+num)%13] %= MOD;
            }
        }
    }
    cout << dp[n-1][5] << endl;
}