#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int ctoi(char c){
    switch (c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

int main(){
    string S;
    cin >> S;
    int len = S.size();
    vector<vector<ll> > dp(len,vector<ll>(13));
    rep(i,len){
        rep(j,13){
            dp[i][j] = 0;
        }
    }
    if (S[0] == '?'){
        rep(i,10){
            dp[0][i]++;
        }
    }
    else{
        dp[0][ctoi(S[0])]++;
    }
    for (int i = 0; i < len - 1; i++){
        if (S[i + 1] == '?'){
            rep(j,13){
                rep(k,10){
                    dp[i + 1][(10 * j + k) % 13] = (dp[i + 1][(10 * j + k) % 13] + dp[i][j]) % 1000000007;
                }
            }
        }
        else{
            rep(j,13){
                dp[i + 1][(10 * j + ctoi(S[i + 1])) % 13] = (dp[i + 1][(10 * j + ctoi(S[i + 1])) % 13] + dp[i][j]) % 1000000007;
            }
        }
    }
    cout << dp[len - 1][5] << endl;
}
