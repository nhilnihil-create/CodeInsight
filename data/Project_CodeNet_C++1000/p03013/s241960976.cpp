#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<bool> a(N + 1, true);
    for(int i = 0; i < M; i++){
        int t;
        cin >> t;
        a[t] = false;
    }
    const int MOD = 1e9 + 7;
    vector<long long> dp(N + 1);
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        if(!a[i]) continue;
        if(i + 1 <= N){
            dp[i + 1] += dp[i];
            dp[i + 1] %= MOD;
        }
        if(i + 2 <= N){
            dp[i + 2] += dp[i];
            dp[i + 2] %= MOD;
        }
    }
    cout << dp[N] << endl;
}