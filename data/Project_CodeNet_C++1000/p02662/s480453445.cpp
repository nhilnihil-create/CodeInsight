#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main() {
    
    long long N,S;
    cin >> N >> S;
    long long A[N];
    for(int i = 0; i < N;i++)cin >> A[i];
    
    long long DP[N+1][S+1];
    
    for(int i = 0; i <= N;i++){
        for(int j = 0; j <= S;j++)DP[i][j] = 0;
    }
    
    DP[0][0] = 1;
    long long MOD = 998244353;
    
    for(int i = 0; i < N ;i++){
        for(int j = 0; j <= S;j++){
            
            DP[i+1][j] += DP[i][j]*2 % MOD;
            if(j - A[i]>=0)DP[i+1][j] += DP[i][j-A[i]];
            DP[i+1][j] %= MOD;
            
        }
    }
    cout << DP[N][S]<<endl;
}
