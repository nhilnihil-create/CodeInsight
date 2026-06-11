#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(long long int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

using llint = long long int;

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){

    string s;cin>>s;
    llint n = s.size();
    vector<vector<llint>>dp(2, vector<llint>(n + 1, 0));
    dp[0][0] = 1;
    dp[1][0] = 2;
    FOR(i,1,n){
        if(s[i]=='1'){
            dp[1][i] += dp[1][i - 1] * 2;
            dp[0][i] += dp[1][i - 1] + dp[0][i - 1] * 3;
        }else{
            dp[1][i] = dp[1][i - 1];
            dp[0][i] += dp[0][i - 1] * 3;
        
        }
        dp[1][i] %= mod;
        dp[0][i] %= mod;
        
    }
    cout <<(dp[0][n-1]+ dp[1][n - 1])%mod << endl;
    return 0;
}
