#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)

ll dp[100005][13];

int main(){
    string s;
    cin >> s;
    int n = s.size();
    
    ll mod = 1e9+7;
    dp[0][0] = 1;
    
    for(int i = 0;i <= n;i++){
        for(int j = 0;j < 10;j++){
            if(s[i]-'0' != j && s[i] != '?')continue;
            
            for(int l = 0;l < 13;l++){
                dp[i+1][(l * 10 + j) % 13] += dp[i][l];
                dp[i+1][(l * 10 + j) % 13] %= mod;
            }
        }
    }
    
    cout << dp[n][5] << endl;
}