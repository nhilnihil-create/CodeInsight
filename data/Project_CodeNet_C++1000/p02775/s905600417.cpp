#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    string N;
    cin >> N;
    ll size = N.size();


    // 最上位桁を繰り上げると1,繰り上げないと0
    ll dp[size+1][2] = {};
    bool moveUp =false;
    dp[1][0] = N[size-1]-'0';
    dp[1][1] = 10-(N[size-1]-'0');
    for(ll i=1LL;i<size;i++){
        int digit = N[size-1-i] - '0';
        if(digit == 9){
            dp[i+1][0] = dp[i][1] + digit;
        }else{
            dp[i+1][0] = min(dp[i][0] + digit,dp[i][1] +digit+1);
        }
        dp[i+1][1] = min(dp[i][0] +(10-digit),dp[i][1] +(9-digit) );
    }

    cout << min(dp[size][0],dp[size][1]+1) << endl;
    
    return 0;
}