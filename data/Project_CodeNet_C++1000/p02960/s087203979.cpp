#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 1000000007;
ll dp[1000000][13];

int main() {
    string S; cin >> S;
    int s = S.size();
    dp[0][0] = 1;
    int mul = 1;
    rep(i, s){
        char c = S[s-1-i];
        if(c != '?'){
            int x = c - '0';
            x *= mul;
            x %= 13;
            rep(j, 13){
                dp[i+1][(j+x)%13] += dp[i][j];
            }
        } else {
            rep(k, 10){
                int x = k*mul;
                x %= 13;
                rep(j, 13){
                dp[i+1][(j+x)%13] += dp[i][j];
                }
            }
        }
        rep(j, 13){
            dp[i+1][j] %= mod;
        }
        mul *= 10;
        mul %= 13;
    }

    cout << dp[s][5] << endl;

    /*rep(i, s+1){
        rep(j, 13){
            cout << "dp" << i << j << "=" << dp[i][j] << endl;
        }
    }*/



    return 0;
}