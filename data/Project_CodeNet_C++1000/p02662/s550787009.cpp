#include <bits/stdc++.h>
using namespace std;

constexpr long long int mod = 998244353;
int main(){
    int N,S; cin >> N >> S;
    vector<int> A(3010);
    for(int i=0;i<N;++i){
        cin >> A[i];
    }
    vector<vector<long long int>> dp(3030,vector<long long>(3030));
    dp[0][0] = 1;
    for(int i=0;i<N;++i){
        for(int j=0;j<S+1;++j){
            dp[i+1][j] += 2 * dp[i][j];
            dp[i+1][j] %= mod;
            if(j + A[i] <= S){
                dp[i+1][j+A[i]] += dp[i][j];
                dp[i+1][j+A[i]] %= mod;
            }
        }
    }
    cout << dp[N][S] << endl;
}