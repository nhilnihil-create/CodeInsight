#include <iostream>

using namespace std;

int dp[5005][5005];

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    for(int i=0; i<5005; i++){
        for(int j=0; j<5005; j++){
            dp[i][j] = 0;
        }
    }

    for(int i=N-1; i>=0; i--){
        for(int j=N-1; j>=0; j--){
            if(S[i] == S[j]) dp[i][j] = dp[i+1][j+1] + 1;
            else dp[i][j] = 0;
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i >= j) continue;
            if(dp[i][j] > j-i) continue;
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
