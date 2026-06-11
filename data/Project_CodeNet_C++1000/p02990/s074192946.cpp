#include<bits/stdc++.h>
using namespace std;
using li = long long int;
const int MOD = 1000000007;

int N, K;
li dp[2010][2010] = { 0 };

void make_Comb(int N){
    for(int n = 0; n <= N; n++){
        for(int r = 0; r <= N; r++){
            if(r == 0) dp[n][r] = 1;
            else if(n < r) dp[n][r] = 0;  //r > 0 so including n == 0
            else dp[n][r] = (dp[n-1][r-1] + dp[n-1][r]) % MOD;
        }
    }
    return ;
}

int main(){
    cin >> N >> K;
    make_Comb(N);

    for(int i = 1; i <= K; i++)  cout << (dp[K-1][i-1] * dp[N-K+1][i]) % MOD << endl;
    return 0;
}
