#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
int dp[110000][13];
const int mod = 1000000007;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    dp[0][0] = 1;
    rep(i,n)rep(j,13){
        if(s[i] == '?')rep(a,10){
            (dp[i+1][(j*10+a)%13] += dp[i][j])%mod;
            dp[i+1][(j*10+a)%13] %= mod;
        }
        else{
            int x = s[i] - '0';
            (dp[i+1][(j*10+x)%13] += dp[i][j])%mod;
            dp[i+1][(j*10+x)%13] %=mod;

        }
    }
    cout << dp[n][5]%mod << endl;




    return 0;
}