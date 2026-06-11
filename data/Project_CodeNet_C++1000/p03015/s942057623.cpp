#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)
#define MAX_M 100002
// cout << setprecision(10)

using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;


ll dp[MAX_M][2];
string S;
int main(void){
    cin >> S;
    dp[0][0] = 2;
    dp[0][1] = 1;
    for(int i=1;i<S.length();i++){
        if(S[i] == '0'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = (dp[i-1][1] * 3) % MOD;
        }else{
            dp[i][0] = (dp[i-1][0] * 2) % MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 3)% MOD;
        }
    }
    cout << (dp[S.length()-1][0] + dp[S.length()-1][1])%MOD << endl;
    return 0;
}

