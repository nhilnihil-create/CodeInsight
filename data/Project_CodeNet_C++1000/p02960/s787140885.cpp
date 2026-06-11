#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    string S;
    cin >> S;
    
    reverse(S.begin(), S.end());

    ll dp[S.length()+1][13];
    for(int i=0; i<=S.length(); i++){
        for(int j=0; j<13; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    
    ll dg = 1;
    for(int i=0; i<S.length(); i++){
        // cout << "------ " <<i << endl;
        // cout << dg << endl;
        for(int j=0; j<13; j++){
            if(S[i] != '?'){
                int d = S[i] - '0';
                int nd = (dg*d + j)%13;
                dp[i+1][nd] += dp[i][j];
                dp[i+1][nd] %= MOD;
                continue;
            }

            // cout << "---- " << j << endl;
            for(int k=0; k<10; k++){
                // int nd = (dg*k + j)%13;
                int nd = dg*k + j;
                nd %= 13;
                // cout << k << " " << dg << " " << nd << endl;
                dp[i+1][nd] += dp[i][j];
                dp[i+1][nd] %= MOD;
            }
        }
        dg = (dg * 10) %13;
    }

    cout << dp[S.length()][5] << endl;

    return 0;
}
