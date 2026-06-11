#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = (int)S.size();
    vector<vector<long long>> dp1(N, vector<long long>(2)), dp2(N, vector<long long>(2));//dp1が一致、dp2がそれ未満
    const int MOD = 1e9 + 7;
    dp1[0][1] = 2;
    dp2[0][0] = 1;
    for(int i = 1; i < N; i++){
        if(S[i] == '1'){
            dp1[i][1] += dp1[i - 1][1] * 2 + dp1[i - 1][0] * 2;
            dp2[i][1] += dp2[i - 1][0] * 2 + dp2[i - 1][1] * 2;
            dp2[i][0] += dp1[i - 1][0] + dp1[i - 1][1] + dp2[i - 1][0] + dp2[i - 1][1];
        }
        else{
            dp1[i][0] += dp1[i - 1][1] + dp1[i - 1][0];
            dp2[i][1] += dp2[i - 1][0] * 2 + dp2[i - 1][1] * 2;
            dp2[i][0] += dp2[i - 1][0] + dp2[i - 1][1];
        }
        for(int j = 0; j < 2; j++){
            dp1[i][j] %= MOD;
            dp2[i][j] %= MOD;
        }
    }
    long long ans = 0;
    for(int i = 0; i < 2; i++){
        ans += dp1[N - 1][i] + dp2[N - 1][i];
    }
    cout << ans % MOD << endl;
}