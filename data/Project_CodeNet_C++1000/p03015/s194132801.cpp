#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD =ll(1e9) +7;

int main() {
    string S;
    cin >> S;
    ll dp[S.size()+1][2] ={};
    dp[0][0] =1;
    for(int i=0;i<S.size();i++){
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
        dp[i+1][1] *=3;
        int t = S[i] -'0';
        for(int d=0;d<2;d++){
            if(d<t){
                dp[i+1][0] *= 2;
                dp[i+1][1]+=dp[i][0];
            }
        }
        dp[i+1][0] %=MOD;
        dp[i+1][1] %=MOD;
    }
    cout << (dp[S.size()][0] + dp[S.size()][1])%MOD << endl;

    return 0;
}